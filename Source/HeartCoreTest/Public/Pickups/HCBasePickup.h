// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "HCBasePickup.generated.h"

class USphereComponent;
UCLASS()
class HEARTCORETEST_API AHCBasePickup : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pickup")
	USphereComponent* CollisionComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Pickup")
	float RespawnTime = 5.0f;

	AHCBasePickup();

protected:
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:
	virtual void Tick(float DeltaTime) override;
	bool CouldBeTaken() const;
private:
	float RotationYaw = 0.0f;
	FTimerHandle RespawnTimerHandle;

	virtual bool GivePickupTo(APawn* PlayerPawn);
	void PickupWasTaken();
	void Respawn();
	void GenerateRotationYaw();
};
