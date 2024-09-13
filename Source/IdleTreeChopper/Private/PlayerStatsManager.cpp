// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsManager.h"

float UPlayerStatsManager::GetValue(const EPlayerStat PlayerStat)
{
	switch (PlayerStat)
	{
	case EPlayerStat::AttackDamage:
		return PlayerStats.AttackDamage;
	case EPlayerStat::AttackSpeed:
		return PlayerStats.AttackSpeed;
	case EPlayerStat::MoneyMultiplier:
		return PlayerStats.MoneyMultiplier;
	case EPlayerStat::MovementSpeed:
		return PlayerStats.MovementSpeed;
	case EPlayerStat::StorageMultiplier:
		return PlayerStats.StorageMultiplier;
	case EPlayerStat::CoinBagSize:
		return PlayerStats.CoinBagSize;

	default: return 1;
	}
}

FString UPlayerStatsManager::GetName(const EPlayerStat PlayerStat)
{
	switch (PlayerStat)
	{
	case EPlayerStat::AttackDamage:
		return "Attack Damage";
	case EPlayerStat::AttackSpeed:
		return "Attack Speed";
	case EPlayerStat::MoneyMultiplier:
		return "Money Multiplier";
	case EPlayerStat::MovementSpeed:
		return "Movement Speed";
	case EPlayerStat::StorageMultiplier:
		return "Storage Multiplier";
	case EPlayerStat::CoinBagSize:
		return "Coin Bag Size";

	default: return "";
	}
}
