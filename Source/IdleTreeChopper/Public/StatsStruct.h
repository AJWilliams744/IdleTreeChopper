// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StatsStruct.generated.h"  // Ensure the header is generated correctly
/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlayerStatsStructure
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoneyMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float StorageMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CoinBagSize;

	FPlayerStatsStructure()
	{
		MovementSpeed = 1;
		AttackDamage = 1;
		MoneyMultiplier = 1;
		StorageMultiplier = 1;
		CoinBagSize = 1;
	}
};

UENUM(BlueprintType)
enum class EPlayerStat : uint8
{
	MovementSpeed UMETA(DisplayName="MovementSpeed"),
	AttackDamage UMETA(DisplayName="AttackDamage"),
	MoneyMultiplier UMETA(DisplayName="MoneyMultiplier"),
	StorageMultiplier UMETA(DisplayName="StorageMultiplier"),
	CoinBagSize UMETA(DisplayName="CoinBagSize"),
};
