// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "PlayerStatistic.generated.h"

/**
 * 
 */

#define SIZE 6
#define Slime 0
#define Skeleton 1
#define Flower 2
#define Magic 3
#define Healer 4
#define Golem 5

UCLASS()
class IEGPROJECT_API UPlayerStatistic : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<int32> MonsterKill ;
	UPROPERTY(BlueprintReadWrite)
	int32 PlayerLife ;
    

	UPlayerStatistic();

	UFUNCTION(BlueprintCallable)
	void addMonsterKill(int32 Index) ;

	UFUNCTION(BlueprintCallable)
	void clearMonsterKill() ;

	UFUNCTION(BlueprintCallable)
	void SubPlayerLife() ;

	UFUNCTION(BlueprintCallable)
	bool IsEnd() ;

	UFUNCTION(BlueprintCallable)
	int32 getSlime() ;
	UFUNCTION(BlueprintCallable)
	int32 getSkeleton() ;
	UFUNCTION(BlueprintCallable)
	int32 getFlower() ;
	UFUNCTION(BlueprintCallable)
	int32 getMagic() ;
	UFUNCTION(BlueprintCallable)
	int32 getHealer() ;
	UFUNCTION(BlueprintCallable)
	int32 getGolem() ;

	UFUNCTION(BlueprintCallable)
	int32 getScore() ;
};
