// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManager.h"

void UInventoryManager::AddItem(TSubclassOf<UInventoryItem> ClassType, int Quantity)
{
	if (!IsClassTypeInArray(ClassType))
	{
		UInventoryItem* addItem = NewObject<UInventoryItem>(this, ClassType);
		addItem->Quantity = Quantity;
		InventoryItems.Add(addItem);
	}
	else
	{
		UInventoryItem* foundItem = GetItem(ClassType);
		foundItem->Quantity += Quantity;
	}
}

void UInventoryManager::RemoveItem(TSubclassOf<UInventoryItem> ClassType, int Quantity)
{
	if (!IsClassTypeInArray(ClassType)) return;

	UInventoryItem* foundItem = GetItem(ClassType);
	foundItem->Quantity -= Quantity;

	if (foundItem->Quantity <= 0)
	{
		foundItem->Quantity = 0;
	}
}

UInventoryItem* UInventoryManager::GetItem(TSubclassOf<UInventoryItem> ClassType) const
{
	for (UInventoryItem* Item : InventoryItems)
	{
		if (Item && Item->IsA(ClassType))
		{
			return Item;
		}
	}
	return nullptr;
}

UInventoryItem* UInventoryManager::GetItemByName(const FString& ItemName) const
{
	for (UInventoryItem* Item : InventoryItems)
	{
		if (Item && Item->GetName().Equals(ItemName, ESearchCase::IgnoreCase))
		{
			return Item;
		}
	}
	return nullptr;
}

bool UInventoryManager::IsClassTypeInArray(TSubclassOf<UInventoryItem> ClassType)
{
	for (UInventoryItem* Item : InventoryItems)
	{
		if (Item && Item->IsA(ClassType))
		{
			return true;
		}
	}
	return false;
}
