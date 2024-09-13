// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopItem.h"

#include "Coins.h"
#include "InventoryManager.h"
#include "PlayerStatsManager.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UShopItem::NativeConstruct()
{
	Super::NativeConstruct();

	if (!ItemClass)
	{
		UE_LOG(LogTemp, Error, TEXT("No Item Class Selected"));
		return;
	}

	Item = NewObject<UInventoryItem>(this, ItemClass);

	if (Buying)
	{
		ButtonText->SetText(FText::FromString("Buy"));
	}
	else
	{
		ButtonText->SetText(FText::FromString("Sell"));
	}

	Button->OnClicked.AddDynamic(this, &UShopItem::ButtonClicked);

	QuantityText->SetText(FText::FromString("x0"));

	NameText->SetText(FText::FromString(Item->GetName()));
	PriceText->SetText(FText::Format(
		FText::FromString(TEXT("{0}{1}{2}")),
		FText::FromString("Price: "),
		FText::AsNumber(0),
		FText::FromString("G")));
}

void UShopItem::UpdateData(UInventoryManager* InInventoryManager, UPlayerStatsManager* InStatsManager)
{
	InventoryManager = InInventoryManager;
	StatsManager = InStatsManager;

	Item = InventoryManager->GetItem(ItemClass);

	if (!Item) Item = NewObject<UInventoryItem>(this, ItemClass);

	QuantityText->SetText(FText::AsNumber(Item->Quantity));

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Item->GetName());

	FInventoryItemData ItemData = InventoryManager->InventoryData[Item->GetName()];

	PriceText->SetText(FText::Format(
		FText::FromString(TEXT("{0}{1}{2}")),
		FText::FromString("Price: "),
		FText::AsNumber(ItemData.SellPrice * StatsManager->GetStatValue(EPlayerStat::MoneyMultiplier)),
		FText::FromString("G")));
}

void UShopItem::ButtonClicked()
{
	if (!Item) Item = NewObject<UInventoryItem>(this, ItemClass);
	if (!Buying)
	{
		if (Item->Quantity > 0)
		{
			InventoryManager->AddItem(UCoins::StaticClass(), InventoryManager->InventoryData[Item->GetName()].SellPrice * StatsManager->GetStatValue(EPlayerStat::MoneyMultiplier));
			InventoryManager->RemoveItem(ItemClass, 1);
		}
	}

	UpdateData(InventoryManager, StatsManager);
}
