// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MagicMissile.h"
#include "MyMainChar.generated.h"

#define SIZE 6
#define Slime 0
#define Skeleton 1
#define Flower 2
#define Magic 3
#define Healer 4
#define Golem 5

UCLASS()
class IEGPROJECT_API AMyMainChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyMainChar();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;	
	UPROPERTY(BlueprintReadWrite,Category= bool)
	bool Attack ;
	UPROPERTY(BlueprintReadWrite,Category= bool)
	bool IsDead ;
	UPROPERTY(BlueprintReadWrite,Category= bool)
	bool Invinceble ;
	
	UPROPERTY(BlueprintReadWrite,Category= int32)
	int32 AttackIndex ;
	UPROPERTY(BlueprintReadWrite,Category= int32)
	int32 SkillType ;
	UPROPERTY(BlueprintReadWrite,Category= int32)
	int32 AttackType;
	UPROPERTY(BlueprintReadWrite,Category= int32)
	TArray<int32> WeaponIndex ;

	UPROPERTY(BlueprintReadWrite,Category= int32)
	int32 Level ;
	UPROPERTY(BlueprintReadWrite,Category= int32)
	int32 Point ;

	UPROPERTY(BlueprintReadWrite,Category=float)
	float Speed;
	UPROPERTY(BlueprintReadWrite,Category=float)
	float MaxHealth;
	UPROPERTY(BlueprintReadWrite,Category= float)
	float CurrentHealth;
	UPROPERTY(BlueprintReadWrite,Category=float)
	float MaxEnergy;
	UPROPERTY(BlueprintReadWrite,Category= float)
	float CurrentEnergy;
	UPROPERTY(BlueprintReadWrite,Category= float)
	float MagicPower;
	UPROPERTY(BlueprintReadWrite,Category= float)
	float MagicCost;
	UPROPERTY(BlueprintReadWrite,Category= float)
    float AttackPower;
	UPROPERTY(BlueprintReadWrite,Category= float)
	float AttackBonus;
	UPROPERTY(BlueprintReadWrite,Category= float)
	float MagicBonus;
	UPROPERTY(BlueprintReadWrite,Category= float)
	float AttackRate;
	UPROPERTY(BlueprintReadWrite,Category= float)
	float AddEnergyValue;
	
	UPROPERTY(BlueprintReadWrite,Category= Montage)
	UAnimMontage * DieMontage ;

	UFUNCTION(BlueprintCallable)
	void SetSkillType() ;
	UFUNCTION(BlueprintCallable)
	void SubHealth(float Damage);
	UFUNCTION(BlueprintCallable)
	void AddHealth(float Heal);
	UFUNCTION(BlueprintCallable)
	void Revive();
	UFUNCTION(BlueprintCallable)
	void AddEnergy(float EnergyAddValue);

	UPROPERTY(BlueprintReadWrite,Category= bool)
	TArray<bool> Equiped ;
	UPROPERTY(BlueprintReadWrite,Category= bool)
	bool IsMagic ;
	UFUNCTION(BlueprintCallable)
	void GetAttackType();
	UFUNCTION(BlueprintCallable)
	int32 GetPickSituation(int32 SocketIndex);
	UFUNCTION(BlueprintCallable)
	int32 SkillSituation();

	UFUNCTION()
	void MoveForward(float Value);
	UFUNCTION()
	void MoveRight(float Value);
	UFUNCTION()
	void StartJump();
	UFUNCTION()
	void StopJump();
	UFUNCTION(BlueprintCallable)
	void SpeedUp();
	UFUNCTION(BlueprintCallable)
	void SpeedDown();
	
	
	UFUNCTION(BlueprintCallable)
	void ResetAttack();
	UFUNCTION(BlueprintCallable)
	float getAttackDamage();
	UFUNCTION(BlueprintCallable)
	float getMagicDamage();

	UFUNCTION(BlueprintCallable)
	void LevelUp();
	UFUNCTION(BlueprintCallable)
	TArray<int32> getTarget();
	UFUNCTION(BlueprintCallable)
	bool LevelUpCondition(TArray<int32> MonsterKill);
	UFUNCTION(BlueprintCallable)
	bool ConsumePoint();

	UFUNCTION(BlueprintCallable)
	void addAttackBonus(float Bonus);
	UFUNCTION(BlueprintCallable)
	void addMagicBonus(float Bonus);
	UFUNCTION(BlueprintCallable)
	void addMaxHealth(float Bonus);
	UFUNCTION(BlueprintCallable)
	void addMaxEnergy(float Bonus);
	UFUNCTION(BlueprintCallable)
	void addSpeed(float Bonus);
};