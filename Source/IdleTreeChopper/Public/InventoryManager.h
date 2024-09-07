// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "InventoryManager.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UInventoryManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<UInventoryItem*> InventoryItems;

	// Functions to manage the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(TSubclassOf<UInventoryItem> ClassType, int Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(TSubclassOf<UInventoryItem> ClassType, int Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UInventoryItem* GetItem(TSubclassOf<UInventoryItem> ClassType) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UInventoryItem* GetItemByName(const FString& ItemName) const;

	bool IsClassTypeInArray(TSubclassOf<UInventoryItem> ClassType);
};
