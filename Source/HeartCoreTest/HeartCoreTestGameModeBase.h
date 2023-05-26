// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "HeartCoreTestGameModeBase.generated.h"

class AAIController;
UCLASS()
class HEARTCORETEST_API AHeartCoreTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	AHeartCoreTestGameModeBase();

public:
	void EndRound(AActor* Winner);

	virtual void StartPlay() override;
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

	UFUNCTION(BlueprintCallable)
	bool IsRestartPlayer() { return IsRestart; }
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Game")
	TSubclassOf<AAIController> AIControllerClass;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
	TSubclassOf<APawn> AIPawnClass;

private:
	void ResetPlayers();
	void ResetOnePlayer(AController* Controller);

	void SpawnBot();

	bool IsRestart = false;
};
