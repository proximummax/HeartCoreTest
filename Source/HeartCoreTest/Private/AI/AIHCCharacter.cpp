// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AIHCCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AI/HCAIController.h"

AAIHCCharacter::AAIHCCharacter()
{
	AutoPossessAI = EAutoPossessAI::Disabled;
	AIControllerClass = AHCAIController::StaticClass();

	bUseControllerRotationYaw = false;
	const auto CharacterMovementComponent = GetCharacterMovement();

	if (!CharacterMovementComponent)
		return;

	CharacterMovementComponent->bUseControllerDesiredRotation = true;
	CharacterMovementComponent->RotationRate = FRotator(0.0f, 200.0f, 0.0f);
}
