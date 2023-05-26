// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/HCBasePickup.h"
#include "HCHealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class HEARTCORETEST_API AHCHealthPickup : public AHCBasePickup
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "1.0", ClampMax = "100.0"))
	float HealthAmount = 50.0f;
private:
	virtual bool GivePickupTo(APawn* PlayerPawn) override;
};
