// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStatItem.h"

#include "IDetailTreeNode.h"
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
}

void UPlayerStatItem::UpdateData(UPlayerStatsManager* StatsManager)
{
	float value = StatsManager->GetValue(StatType);

	NameText->SetText(FText::FromString(UPlayerStatsManager::GetName(StatType)));
	PriceText->SetText(FText::Format(
		FText::FromString(TEXT("{0}{1}{2}")),
		FText::FromString("Price: "),
		FText::AsNumber(value),
		FText::FromString("G")));
}

void UPlayerStatItem::ButtonClicked()
{
}
