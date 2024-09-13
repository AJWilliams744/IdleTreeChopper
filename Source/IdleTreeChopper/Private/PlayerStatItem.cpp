// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatItem.h"

#include "Coins.h"
#include "IDetailTreeNode.h"
#include "InventoryManager.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UPlayerStatItem::NativeConstruct()
{
	Super::NativeConstruct();

	Button->OnClicked.AddDynamic(this, &UPlayerStatItem::ButtonClicked);

	QuantityText->SetText(FText::FromString("x0"));

	NameText->SetText(FText::FromString(UPlayerStatsManager::GetName(StatType)));
	PriceText->SetText(FText::Format(
		FText::FromString(TEXT("{0}{1}{2}")),
		FText::FromString("Price: "),
		FText::AsNumber(0),
		FText::FromString("G")));

	StatIncreaseText->SetText(FText::FromString("+0.1"));
}

void UPlayerStatItem::UpdateData(UPlayerStatsManager* InStatsManager, UInventoryManager* InInventoryManager)
{
	StatsManager = InStatsManager;
	InventoryManager = InInventoryManager;

	float Value = StatsManager->GetStatValue(StatType);
	Price = StatsManager->GetPurchaseNumber(StatType);

	Price = FMath::FloorToInt(Price * 1.5);

	StatIncreaseText->SetText(FText::Format(
		FText::FromString(TEXT("{0}{1}")),
		FText::FromString("+"),
		FText::AsNumber(0.5)));

	QuantityText->SetText(FText::Format(
		FText::FromString(TEXT("{0}{1}")),
		FText::FromString("x"),
		FText::AsNumber(Value)));

	NameText->SetText(FText::FromString(UPlayerStatsManager::GetName(StatType)));
	PriceText->SetText(FText::Format(
		FText::FromString(TEXT("{0}{1}{2}")),
		FText::FromString("Price: "),
		FText::AsNumber(Price),
		FText::FromString("G")));
}

void UPlayerStatItem::ButtonClicked()
{
	UInventoryItem* Item = InventoryManager->GetItem(UCoins::StaticClass());

	if (!Item) Item = NewObject<UInventoryItem>(this, UCoins::StaticClass());
	if (Item->Quantity > Price)
	{
		StatsManager->AddStatValue(StatType, 0.5);
		InventoryManager->RemoveItem(UCoins::StaticClass(), Price);
	}

	UpdateData(StatsManager, InventoryManager);
}
