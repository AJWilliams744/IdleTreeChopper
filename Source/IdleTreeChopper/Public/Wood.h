// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "Wood.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UWood : public UInventoryItem
{
	GENERATED_BODY()

public:
	virtual FString GetName() override;
	virtual FString GetTextureName() override;
};
