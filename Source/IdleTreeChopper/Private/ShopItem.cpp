// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopItem.h"

#include "InventoryManager.h"
#include "Components/TextBlock.h"

void UShopItem::NativeConstruct()
{
	Super::NativeConstruct();

	if (!ItemClass)
	{
		UE_LOG(LogTemp, Error, TEXT("No Item Class Selected"));
		return;
	}

	UInventoryItem* Item = NewObject<UInventoryItem>(this, ItemClass);

	if (Buying)
	{
		ButtonText->SetText(FText::FromString("Buy"));
	}
	else
	{
		ButtonText->SetText(FText::FromString("Sell"));
	}

	QuantityText->SetText(FText::FromString("x0"));

	NameText->SetText(FText::FromString(Item->GetName()));
	PriceText->SetText(FText::Format(
		FText::FromString(TEXT("{0}{1}{2}")),
		FText::FromString("Price: "),
		FText::AsNumber(0),
		FText::FromString("G")));
}

void UShopItem::UpdateData(UInventoryManager* InventoryManager)
{
	UE_LOG(LogTemp, Warning, TEXT("New data set"));
	UInventoryItem* Item = InventoryManager->GetItem(ItemClass);

	if (!Item) Item = NewObject<UInventoryItem>(this, ItemClass);

	QuantityText->SetText(FText::AsNumber(Item->Quantity));

	PriceText->SetText(FText::Format(
		FText::FromString(TEXT("{0}{1}{2}")),
		FText::FromString("Price: "),
		FText::AsNumber(InventoryManager->InventoryData[Item->GetName()].SellPrice),
		FText::FromString("G")));
}
