// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMainChar.h"

#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AMyMainChar::AMyMainChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Attack = false ;
	Invinceble = false ;
	IsDead = false ;
	AttackIndex = 0 ;
	MaxHealth = 250;
	Level = 1 ;
	Point = 5 ;
	AttackPower = 1;
	MagicPower = 1 ;
	AttackBonus = 1;
	MagicBonus = 1 ;
	MagicCost = 30 ;
	SkillType = -1;
	MaxEnergy = 100 ;
	IsMagic = false ;
	AttackRate =1 ;
	AddEnergyValue = 0 ;
	Speed = 360;
	GetCharacterMovement()->MaxWalkSpeed = Speed;

	Equiped.Init(false,3);
	WeaponIndex.Init(-1,3);
	
	static ConstructorHelpers::FObjectFinder<UAnimMontage> DieMontageObject(TEXT("AnimMontage'/Game/Extra/Red_Knight/Animations/MonDieFront.MonDieFront'"));
	if(DieMontageObject.Succeeded())
	{
		DieMontage = DieMontageObject.Object;
	}
}

// Called when the game starts or when spawned
void AMyMainChar::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	CurrentEnergy = MaxEnergy;
}

// Called every frame
void AMyMainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyMainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyMainChar::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyMainChar::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AMyMainChar::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyMainChar::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyMainChar::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyMainChar::StopJump);
	
}

void AMyMainChar::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AMyMainChar::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AMyMainChar::StartJump()
{
    bPressedJump = true;
}

void AMyMainChar::StopJump()
{
    bPressedJump = false;
}


void AMyMainChar::SpeedUp()
{
	GetCharacterMovement()->MaxWalkSpeed = Speed*10;
}

void AMyMainChar::SpeedDown()
{
	GetCharacterMovement()->MaxWalkSpeed = Speed;
}

void AMyMainChar::SubHealth(float Damage)
{
	CurrentHealth -= Damage ;
	if(CurrentHealth < 0) CurrentHealth = 0 ;
	if(CurrentHealth == 0)
	{
		PlayAnimMontage(DieMontage);
		IsDead = true ;
	}
}

void AMyMainChar::AddHealth(float Heal)
{
	CurrentHealth += Heal ;
	if(CurrentHealth > MaxHealth) CurrentHealth =MaxHealth ;
}

void AMyMainChar::AddEnergy(float EnergyAddValue)
{
	CurrentEnergy+=EnergyAddValue ;
	if(CurrentEnergy > MaxEnergy) CurrentEnergy  = MaxEnergy ;
}

void AMyMainChar::GetAttackType()
{
	if(IsMagic) AttackType=1;
	if(Equiped[2]==true) AttackType=2 ;
	if(Equiped[0] == true) AttackType=3 ;
	AttackType=0 ;
}

int32 AMyMainChar::GetPickSituation(int32 SocketIndex)
{
	if(Equiped[SocketIndex] == true) return 2 ;
	Equiped[SocketIndex] = true ;
	if(SocketIndex == 2)
	{
		if(Equiped[0] == true|| Equiped[1] == true)
		{
			Equiped[0] = false;
			Equiped[1] = false;
			return 0 ;
		}
	}
	else
	{
		if(Equiped[2] == true)
		{
			Equiped[2] = false;
			return 1;
		}
	}
	return 3;
}

void AMyMainChar:: SetSkillType()
{
	if(Equiped[2] == true)
	{
		if(IsMagic == true)
		{
			SkillType = 2 ;
			MagicCost = 18;
			AttackType= 1;
			AttackRate = 0.7;
			AddEnergyValue = 3 ;
			return ;
		}
		else
		{
			SkillType =1 ;
			MagicCost = 40 ;
			AttackType=2 ;
			AttackRate = 0.85;
			AddEnergyValue = 9;
			return ;
		}
	}
	if(Equiped[1]==true)
	{
		SkillType = 0 ;
		MagicCost = 35 ;
	}
	else
	{
		SkillType = -1 ;
		MagicCost = 30;
	}
	if(Equiped[0]==true)
	{
		AttackType= 3 ;
		AttackRate = 1;
		AddEnergyValue = 8 ;
	}
	else
	{
		AttackType= 0 ;
	}
}

int32 AMyMainChar::SkillSituation()
{
	if(Level <= 1) return 1 ;
	if(CurrentEnergy < MagicCost) return 2 ;
	if(SkillType!=0){
		if(Attack == true) return 3 ;
		else Attack = true ;
	}
	CurrentEnergy -= MagicCost ;
	return 0 ;
}


void AMyMainChar::ResetAttack()
{
	Attack = false ;
}

void AMyMainChar::Revive()
{
	CurrentHealth = MaxHealth ;
	CurrentEnergy = MaxEnergy ;
	ResetAttack();
	IsDead = false ;
}

void AMyMainChar::LevelUp()
{
	Level ++ ;
	Point +=2 ;
}

TArray<int32> AMyMainChar::getTarget() {
	TArray<int32> Condition;
	if(Level == 1) Condition = {8,0,0,0,0,0} ;
	else if(Level == 2) Condition = {15,6,3,0,0,0} ;
	else if(Level == 3) Condition = {24,12,6,4,0,0} ;
	else if(Level == 4) Condition = {32,14,10,8,3,0} ;
	else if(Level == 5) Condition = {42,20,15,12,7,2} ;
	else Condition = {999,999,999,999,999,999};
	return Condition;
}

bool AMyMainChar::LevelUpCondition(TArray<int32> MonsterKill)
{
	TArray<int32> Condition = getTarget() ;
	for(int MonsterIndex = 0 ; MonsterIndex < SIZE ; MonsterIndex ++) 
	{
		if(MonsterKill[MonsterIndex] < Condition[MonsterIndex])
		{
			return false;
		}
	}
	LevelUp();
	return true ;
}

bool AMyMainChar::ConsumePoint()
{
	if(Point > 0) {	
		Point -- ;
		return true ;
	}
	return false ;
}

float AMyMainChar::getAttackDamage()
{
	int AttackDamage ;
	AttackDamage = AttackBonus*AttackPower ;
	return AttackDamage ;
}

float AMyMainChar::getMagicDamage()
{
	int MagicDamage ;
	MagicDamage = MagicBonus*MagicPower ;
	return MagicDamage;
}

void AMyMainChar::addAttackBonus(float Bonus)
{
	AttackBonus += Bonus ;
}

void AMyMainChar::addMagicBonus(float Bonus)
{
	MagicBonus += Bonus ;
}

void AMyMainChar::addMaxHealth(float Bonus)
{
	MaxHealth+= Bonus ;
	CurrentHealth = MaxHealth ;
}

void AMyMainChar::addMaxEnergy(float Bonus)
{
	MaxEnergy+= Bonus ;
	CurrentEnergy = MaxEnergy ;
}

void AMyMainChar::addSpeed(float Bonus)
{
	Speed += Bonus;
	GetCharacterMovement()->MaxWalkSpeed = Speed;
}