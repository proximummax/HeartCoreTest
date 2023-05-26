// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/HCBasePickup.h"

AHCBasePickup::AHCBasePickup()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	CollisionComponent->InitSphereRadius(50.0f);
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	SetRootComponent(CollisionComponent);
}

void AHCBasePickup::BeginPlay()
{
	Super::BeginPlay();
	check(CollisionComponent);

	GenerateRotationYaw();
}

void AHCBasePickup::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	const auto Pawn = Cast<APawn>(OtherActor);
	if (!Pawn)
		return;

	if (GivePickupTo(Pawn))
		PickupWasTaken();

}

void AHCBasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, RotationYaw, 0.0f));
}

bool AHCBasePickup::CouldBeTaken() const
{
	return !GetWorldTimerManager().IsTimerActive(RespawnTimerHandle);
}

bool AHCBasePickup::GivePickupTo(APawn* PlayerPawn)
{
	return false;
}

void AHCBasePickup::PickupWasTaken()
{
	CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	if (!GetRootComponent())
		return;

	GetRootComponent()->SetVisibility(false, true);

	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &AHCBasePickup::Respawn, RespawnTime);
}

void AHCBasePickup::Respawn()
{
	GenerateRotationYaw();
	CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	if (!GetRootComponent())
		return;

	GetRootComponent()->SetVisibility(true, true);
}

void AHCBasePickup::GenerateRotationYaw()
{
	const auto Direction = FMath::RandBool() ? 1.0 : -1.0;
	RotationYaw = FMath::RandRange(1.0f, 2.0f) * Direction;

}
