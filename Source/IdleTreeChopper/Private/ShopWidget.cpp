// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopWidget.h"

#include "PopupManager.h"
#include "ShopItem.h"
#include "Components/UniformGridPanel.h"

void UShopWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TArray<UWidget*> Children = SellGrid->GetAllChildren();

	for (UWidget* Child : Children)
	{
		if (!Child) continue;

		UShopItem* ShopItem = Cast<UShopItem>(Child);
		if (!ShopItem)
		{
			continue;
		}

		const AFirstPersonCharacter* Person = Cast<AFirstPersonCharacter>(Character);

		ShopItem->UpdateData(Person->InventoryManager, Person->StatsManager);
	}
}
