// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopItem.h"

#include "Components/TextBlock.h"

void UShopItem::UpdateData(bool Buying, FString Name, float Price)
{
	if (Buying)
	{
		ButtonText->SetText(FText::FromString("Buy"));
	}
	else
	{
		ButtonText->SetText(FText::FromString("Sell"));
	}

	NameText->SetText(FText::FromString(Name));
	PriceText->SetText(FText::Format(
		FText::FromString(TEXT("{0}{1}{2}")),
		FText::FromString("Price: "),
		FText::AsNumber(Price),
		FText::FromString("G")));
}
