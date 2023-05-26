// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups/HCHealthPickup.h"
#include "HeartCoreTest/HCUtils.h"
#include "HeartCoreTest/Public/Components/HealthComponent.h"

bool AHCHealthPickup::GivePickupTo(APawn* PlayerPawn)
{
	const auto HealthComponent = HCUtils::GetSTPlayerComponent<UHealthComponent>(PlayerPawn);
	if (!HealthComponent || HealthComponent->IsDead())
		return false;

	return HealthComponent->TryToAddHealth(HealthAmount);
}