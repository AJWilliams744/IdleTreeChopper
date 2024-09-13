// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Popup.h"
#include "PlayerStats.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UPlayerStats : public UPopup
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void NativeConstruct() override;

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UPlayerStatItem* MovementSpeed;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UPlayerStatItem* AttackSpeed;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UPlayerStatItem* AttackDamage;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UPlayerStatItem* MoneyMultiplier;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UPlayerStatItem* StorageMultiplier;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UPlayerStatItem* CoinBagSize;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UUniformGridPanel* StatsGrid;
};
