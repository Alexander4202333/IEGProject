// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAISword.h"

#include "BehaviorTree/BehaviorTree.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
AEnemyAISword::AEnemyAISword()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MaxHealth = 100;
	IsDead = false ;
}

// Called when the game starts or when spawned
void AEnemyAISword::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth ;
	
}

// Called every frame
void AEnemyAISword::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyAISword::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AEnemyAISword::SubHealth(float Damage)
{
	CurrentHealth -= Damage ;
	if(CurrentHealth <= 0)
	{
		CurrentHealth = 0 ;
		IsDead = true ;
	}
}

void AEnemyAISword::AddHealth(float HealValue)
{
	CurrentHealth += HealValue ;
	if(CurrentHealth > MaxHealth) CurrentHealth =MaxHealth ;
}
