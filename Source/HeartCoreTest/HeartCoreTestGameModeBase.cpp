// Copyright Epic Games, Inc. All Rights Reserved.


#include "HeartCoreTestGameModeBase.h"
#include "Player/HCBaseCharacter.h"
#include "Player/HCPlayerState.h"
#include "AIController.h"
#include "UI/GameHUD.h"

AHeartCoreTestGameModeBase::AHeartCoreTestGameModeBase()
{
	DefaultPawnClass = AHCBaseCharacter::StaticClass();
	HUDClass = AGameHUD::StaticClass();
	PlayerStateClass = AHCPlayerState::StaticClass();
}


void AHeartCoreTestGameModeBase::EndRound(AActor *Winner)
{
	const auto Character = Cast<AHCBaseCharacter>(Winner);
	if(!Character)
		return;

	const auto PlayerState = Cast<AHCPlayerState>(Character->GetPlayerState());
	if(!PlayerState)
		return;;

	PlayerState->AddScore();
	 
	ResetPlayers();
}


void AHeartCoreTestGameModeBase::StartPlay()
{
	Super::StartPlay();

	SpawnBot();
}


void AHeartCoreTestGameModeBase::ResetPlayers()
{
	if (!GetWorld()) return;

	for (auto It = GetWorld()->GetControllerIterator(); It; ++It)
	{
		ResetOnePlayer(It->Get());
	}
}

void AHeartCoreTestGameModeBase::ResetOnePlayer(AController* Controller)
{
	IsRestart = false;

	if (Controller && Controller->GetPawn())
	{
		Controller->GetPawn()->Reset();
	}
	RestartPlayer(Controller);

	IsRestart = true;
}

void AHeartCoreTestGameModeBase::SpawnBot()
{
	IsRestart = false;

	if (!GetWorld()) return;

	FActorSpawnParameters SpawnParameters;

	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	const auto AIController = GetWorld()->SpawnActor<AAIController>(AIControllerClass, SpawnParameters);

	RestartPlayer(AIController);

	IsRestart = true;
}

UClass* AHeartCoreTestGameModeBase::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	if (InController && InController->IsA<AAIController>())
		return AIPawnClass;

	return Super::GetDefaultPawnClassForController_Implementation(InController);
}