// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerHUDWidget.h"

#include "Components/HealthComponent.h"
#include "HeartCoreTest/HCUtils.h"
#include "Player/HCPlayerState.h"

void UPlayerHUDWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();


}

int UPlayerHUDWidget::GetScore() const
{
	const auto PlayerState = Cast<AHCPlayerState>(GetOwningPlayerPawn()->GetPlayerState());
	if (!PlayerState)
		return 0;
	return PlayerState->GetScore();
}

float UPlayerHUDWidget::GetHealthPercent() const
{
	const auto HealthComponent = HCUtils::GetSTPlayerComponent<UHealthComponent>(GetOwningPlayerPawn());
	if (!HealthComponent)
		return 0.0f;

	return HealthComponent->GetHealthPercent();
}

bool UPlayerHUDWidget::IsPlayerAlive() const
{
	const auto HealthComponent = HCUtils::GetSTPlayerComponent<UHealthComponent>(GetOwningPlayerPawn());
	return HealthComponent && !HealthComponent->IsDead();
}

bool UPlayerHUDWidget::IsPlayerSpectating() const
{
	const auto Controller = GetOwningPlayer();
	return Controller && Controller->GetStateName() == NAME_Spectating;
}

bool UPlayerHUDWidget::Initialize()
{
	const auto HealthComponent = HCUtils::GetSTPlayerComponent<UHealthComponent>(GetOwningPlayerPawn());
	if (HealthComponent)
	{
		HealthComponent->OnHealthChanged.AddUObject(this, &UPlayerHUDWidget::OnHealthChanged);
	}

	return Super::Initialize();
}


void UPlayerHUDWidget::OnHealthChanged(float Health, float HealthDelta)
{
	if (HealthDelta < 0.0f)
	{
		OnTakeDamage();
	}

}
