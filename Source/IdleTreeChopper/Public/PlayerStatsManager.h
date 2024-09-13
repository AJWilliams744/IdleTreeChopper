// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StatsStruct.h"
#include "PlayerStatsManager.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UPlayerStatsManager : public UObject
{
	GENERATED_BODY()

public:
	FPlayerStatsStructure PlayerStats;
	float GetValue(EPlayerStat PlayerStat);
	static FString GetName(const EPlayerStat PlayerStat);
};
