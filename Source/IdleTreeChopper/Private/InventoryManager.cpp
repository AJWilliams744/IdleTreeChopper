// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManager.h"

void UInventoryManager::AddItem(UInventoryItem* NewItem)
{
	if (!NewItem) return;

	if (!IsClassTypeInArray(NewItem->GetClass()))
	{
		UInventoryItem* addItem = NewObject<UInventoryItem>(this, NewItem->GetClass());
		addItem->Quantity = NewItem->Quantity;
		InventoryItems.Add(addItem);
	}
	else
	{
		UInventoryItem* foundItem = GetItem(NewItem->GetClass());
		foundItem->Quantity += NewItem->Quantity;

		UE_LOG(LogTemp, Display, TEXT("Item Quantity = %d"), foundItem->Quantity);
	}
}

void UInventoryManager::RemoveItem(UInventoryItem* ItemToRemove)
{
	if (!ItemToRemove || !IsClassTypeInArray(ItemToRemove->GetClass())) return;

	UInventoryItem* foundItem = GetItem(ItemToRemove->GetClass());
	foundItem->Quantity -= ItemToRemove->Quantity;

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
