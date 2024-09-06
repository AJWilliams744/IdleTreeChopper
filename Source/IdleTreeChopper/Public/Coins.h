// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "Coins.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UCoins : public UInventoryItem
{
	GENERATED_BODY()

public:
	virtual FString GetTextureName() override;
	virtual FString GetName() override;

	static FString Name;
};
