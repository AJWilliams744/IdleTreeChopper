// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UInventoryItem : public UObject
{
	GENERATED_BODY()

public:
	int Quantity;

	virtual FString GetName();
	virtual FString GetTextureName();
};
