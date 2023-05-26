// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/HCAIController.h"

AHCAIController::AHCAIController()
{
	bWantsPlayerState = true;
}

void AHCAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AHCAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

}


