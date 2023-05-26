// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "HCAIController.generated.h"


class USTAIPerceptionComponent;
UCLASS()
class HEARTCORETEST_API AHCAIController : public AAIController
{
	GENERATED_BODY()
public:
	AHCAIController();
protected:

	virtual void Tick(float DeltaSeconds) override;
	virtual void OnPossess(APawn* InPawn) override;
};
