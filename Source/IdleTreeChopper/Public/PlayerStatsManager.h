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
	FPlayerStatsStructure PurchaseNumbers;
	float GetStatValue(EPlayerStat PlayerStat);
	float GetPurchaseNumber(EPlayerStat PlayerStat);
	static FString GetName(const EPlayerStat PlayerStat);
	void AddStatValue(EPlayerStat PlayerStat, float Value);

private:
	static float GetValue(EPlayerStat PlayerStat, const FPlayerStatsStructure& PlayerStats);
	static void AddValue(EPlayerStat PlayerStat, FPlayerStatsStructure& PlayerStats, float Value);
};
