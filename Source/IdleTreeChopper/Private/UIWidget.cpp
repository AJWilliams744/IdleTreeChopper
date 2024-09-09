// Fill out your copyright notice in the Description page of Project Settings.


#include "UIWidget.h"

#include "Coins.h"
#include "FirstPersonCharacter.h"
#include "Wood.h"
#include "Components/TextBlock.h"

void UUIWidget::UpdateInfo(AFirstPersonCharacter* Character)
{
	if (!Character)
	{
		UE_LOG(LogTemp, Warning, TEXT("No character"));
		return;
	}


	if (Coins)
	{
		coinText->SetText(FText::AsNumber(Coins->Quantity));
	}
	else
	{
		UInventoryItem* Item = Character->InventoryManager->GetItemByName(UCoins::Name);
		if (Item) Coins = Cast<UCoins>(Item);
		coinText->SetText(FText::AsNumber(0));
	}

	if (Wood)
	{
		woodText->SetText(FText::AsNumber(Wood->Quantity));
	}
	else
	{
		UInventoryItem* Item = Character->InventoryManager->GetItemByName(UWood::Name);
		if (Item) Wood = Cast<UWood>(Item);
		woodText->SetText(FText::AsNumber(0));
	}
}
