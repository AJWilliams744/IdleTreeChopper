// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FInventoryItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FString Texture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 SellPrice;

	FInventoryItemData()
		: Name(TEXT("")), Texture(TEXT("")), SellPrice(0)
	{
	}

	FInventoryItemData(FString InName, FString InTexture, int32 InSellPrice)
		: Name(InName), Texture(InTexture), SellPrice(InSellPrice)
	{
	}
};
