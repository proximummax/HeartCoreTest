// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "HeartCoreTest/HeartCoreTestGameModeBase.h"
#include "EndLevelPoint.generated.h"

UCLASS()
class HEARTCORETEST_API AEndLevelPoint : public ATriggerBox
{
	GENERATED_BODY()

	AEndLevelPoint();
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

private:
	UPROPERTY()
	AHeartCoreTestGameModeBase* GameMode;
};

