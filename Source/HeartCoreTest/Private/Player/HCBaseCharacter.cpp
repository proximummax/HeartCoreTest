// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/HCBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/HealthComponent.h"

AHCBaseCharacter::AHCBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");

	HealthTextComponent = CreateDefaultSubobject<UTextRenderComponent>("HealthTextComponent");
	HealthTextComponent->SetupAttachment(GetRootComponent());
	HealthTextComponent->SetOwnerNoSee(true);

}


void AHCBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHCBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AHCBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AHCBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveBack", this, &AHCBaseCharacter::MoveBack);
	PlayerInputComponent->BindAxis("MoveRight", this, &AHCBaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AHCBaseCharacter::MoveLeft);

	PlayerInputComponent->BindAxis("LookUp", this, &AHCBaseCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &AHCBaseCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AHCBaseCharacter::Jump);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AHCBaseCharacter::Attack);
}

void AHCBaseCharacter::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void AHCBaseCharacter::MoveBack(float Amount)
{
	if (Amount == 0.0f) return;
	AddMovementInput(GetActorForwardVector(), -Amount);
}

void AHCBaseCharacter::MoveRight(float Amount)
{
	if (Amount == 0.0f) return;
	AddMovementInput(GetActorRightVector(), Amount);
}

void AHCBaseCharacter::MoveLeft(float Amount)
{
	if (Amount == 0.0f) return;
	AddMovementInput(GetActorRightVector(), -Amount);
}

void AHCBaseCharacter::Attack()
{
	bAttack = true;

}
bool AHCBaseCharacter::IsAttack()
{
	return bAttack;
}

