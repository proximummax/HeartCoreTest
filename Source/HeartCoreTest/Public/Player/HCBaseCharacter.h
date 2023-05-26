// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/HealthComponent.h"
#include "HCBaseCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;
class UHealthComponent;
class UTextRenderComponent;
UCLASS()
class HEARTCORETEST_API AHCBaseCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	AHCBaseCharacter();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UTextRenderComponent* HealthTextComponent;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Attack")
	bool IsAttack();

public:
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
private:

	void MoveForward(float Amount);
	void MoveBack(float Amount);
	void MoveRight(float Amount);
	void MoveLeft(float Amount);

	void Attack();

	bool bAttack = false;
	void OnHealthChanged(float Health, float HealthDelta);


};
