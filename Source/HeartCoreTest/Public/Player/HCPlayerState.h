// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "HeartCoreTest/HCCoreTypes.h"
#include "HCPlayerState.generated.h"


UCLASS()
class HEARTCORETEST_API AHCPlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	FOnScoreChanged OnScoreChanged;

	void AddScore()
	{
		ScoreNum++;
		OnScoreChanged.Broadcast();
	}
	
	int GetScore() { return ScoreNum; }

private:
	int32 ScoreNum = 0;
};
