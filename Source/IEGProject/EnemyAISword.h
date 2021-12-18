// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyAISword.generated.h"

UCLASS()
class IEGPROJECT_API AEnemyAISword : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyAISword();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	UPROPERTY(BlueprintReadWrite,Category=float)
	float MaxHealth;

	UPROPERTY(BlueprintReadWrite,Category= float)
	float CurrentHealth;

	UPROPERTY(BlueprintReadWrite,Category= bool)
	bool IsDead;

	UFUNCTION(BlueprintCallable)
	void SubHealth(float Damage);
	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(BlueprintCallable)
	void AddHealth(float HealValue);

};
