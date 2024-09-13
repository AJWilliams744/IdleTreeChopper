// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatsManager.h"

float UPlayerStatsManager::GetStatValue(const EPlayerStat PlayerStat)
{
	return GetValue(PlayerStat, PlayerStats);
}

float UPlayerStatsManager::GetPurchaseNumber(const EPlayerStat PlayerStat)
{
	return GetValue(PlayerStat, PurchaseNumbers);
}

FString UPlayerStatsManager::GetName(const EPlayerStat PlayerStat)
{
	switch (PlayerStat)
	{
	case EPlayerStat::AttackDamage:
		return "Attack Damage";
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

void UPlayerStatsManager::AddStatValue(const EPlayerStat PlayerStat, const float Value)
{
	AddValue(PlayerStat, PlayerStats, Value);
	AddValue(PlayerStat, PurchaseNumbers, 1);
}

float UPlayerStatsManager::GetValue(const EPlayerStat PlayerStat, const FPlayerStatsStructure& PlayerStats)
{
	switch (PlayerStat)
	{
	case EPlayerStat::AttackDamage:
		return PlayerStats.AttackDamage;
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

void UPlayerStatsManager::AddValue(const EPlayerStat PlayerStat, FPlayerStatsStructure& PlayerStats, const float Value)
{
	switch (PlayerStat)
	{
	case EPlayerStat::AttackDamage:
		PlayerStats.AttackDamage += Value;
		break;

	case EPlayerStat::MoneyMultiplier:
		PlayerStats.MoneyMultiplier += Value;
		break;

	case EPlayerStat::MovementSpeed:
		PlayerStats.MovementSpeed += Value;
		break;

	case EPlayerStat::StorageMultiplier:
		PlayerStats.StorageMultiplier += Value;
		break;

	case EPlayerStat::CoinBagSize:
		PlayerStats.CoinBagSize += Value;
		break;
	}
}
