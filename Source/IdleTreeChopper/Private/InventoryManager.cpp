// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManager.h"
#include "Json.h"               // For FJsonObject, FJsonSerializer
#include "JsonUtilities.h"       // For JSON utilities like FJsonObjectConverter
#include "Misc/FileHelper.h"     // For FFileHelper::LoadFileToString
#include "Misc/Paths.h"          // For FPaths::ProjectContentDir()

void UInventoryManager::AddItem(TSubclassOf<UInventoryItem> ClassType, int Quantity)
{
	if (!ClassType)
	{
		UE_LOG(LogTemp, Error, TEXT("InventoryManager::AddItem: ClassType is null"));
		return;
	}

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

void UInventoryManager::LoadInventoryDataFromJSON()
{
	FString FilePath = FPaths::ProjectContentDir() + TEXT("/Data/InventoryItemsData.json");
	FString JsonContent;

	// Load the JSON file into a string
	if (!FFileHelper::LoadFileToString(JsonContent, *FilePath))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load inventory JSON file!"));
		return;
	}

	// Parse the JSON string
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonContent);

	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		// Get the array of items
		TArray<TSharedPtr<FJsonValue>> ItemsArray = JsonObject->GetArrayField(TEXT("Items"));

		for (TSharedPtr<FJsonValue> ItemValue : ItemsArray)
		{
			TSharedPtr<FJsonObject> ItemObject = ItemValue->AsObject();

			// Extract data
			FString Name = ItemObject->GetStringField(TEXT("Name"));
			FString Texture = ItemObject->GetStringField(TEXT("Texture"));
			int32 SellPrice = ItemObject->GetIntegerField(TEXT("SellPrice"));

			InventoryData.Add(Name, FInventoryItemData(Name, Texture, SellPrice));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to parse inventory JSON file!"));
	}
}
