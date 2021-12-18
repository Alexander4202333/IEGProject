// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatistic.h"

UPlayerStatistic::UPlayerStatistic()
{
	MonsterKill.Init(0,SIZE);
	PlayerLife = 3 ;
}


void UPlayerStatistic::addMonsterKill(int32 Index)
{
	MonsterKill[Index]++;
}

void UPlayerStatistic::clearMonsterKill()
{
	for(int Index = 0 ; Index < SIZE ; Index ++)
	{
		MonsterKill[Index] = 0 ;
	}
}

void UPlayerStatistic::SubPlayerLife()
{
	PlayerLife -- ;
}

bool UPlayerStatistic::IsEnd(){
	SubPlayerLife();
	if(PlayerLife == 0) return true ;
	return false ;
}

int32 UPlayerStatistic::getSlime()
{
	return MonsterKill[Slime] ;
}

int32 UPlayerStatistic::getSkeleton()
{
	return MonsterKill[Skeleton] ;
}
int32 UPlayerStatistic::getFlower()
{
	return MonsterKill[Flower] ;
}
int32 UPlayerStatistic::getMagic()
{
	return MonsterKill[Magic] ;
}
int32 UPlayerStatistic::getHealer()
{
	return MonsterKill[Healer] ;
}
int32 UPlayerStatistic::getGolem()
{
	return MonsterKill[Golem] ;
}

int32 UPlayerStatistic::getScore() 
{
	int32 Score = 0 ;
	for(int Index = 0 ; Index < SIZE ; Index ++)
	{
		Score += MonsterKill[Index]*(2 + Index) ;
	}
	return Score;
}