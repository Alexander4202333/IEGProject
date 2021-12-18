// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicMissile.h"

#include "GameFramework/PawnMovementComponent.h"

// Sets default values
AMagicMissile::AMagicMissile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if(!RootComponent)
	{
		RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MagicSceneComponent"));
	}

	if(!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
		CollisionComponent->InitSphereRadius(30.0f);
		RootComponent = CollisionComponent ;
	}

	if(!ProjectileMovementComponent)
	{
		ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
		ProjectileMovementComponent-> SetUpdatedComponent(CollisionComponent) ;
		ProjectileMovementComponent->InitialSpeed = 1000.0f ;
		ProjectileMovementComponent->MaxSpeed = 1000.0f ;
		ProjectileMovementComponent->bRotationFollowsVelocity=true ;
		ProjectileMovementComponent->bShouldBounce=true;
		ProjectileMovementComponent->Bounciness = 0.3f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.0f ;
	}

}

// Called when the game starts or when spawned
void AMagicMissile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMagicMissile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMagicMissile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection*ProjectileMovementComponent->InitialSpeed ;
}

