// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopWidget.h"

#include "PopupManager.h"
#include "ShopItem.h"
#include "Components/Button.h"
#include "Components/UniformGridPanel.h"

void UShopWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ExitButton->OnClicked.AddDynamic(this, &UShopWidget::ShopClosed);

	TArray<UWidget*> Children = SellGrid->GetAllChildren();

	for (UWidget* Child : Children)
	{
		if (!Child) continue;

		UShopItem* ShopItem = Cast<UShopItem>(Child);
		if (!ShopItem)
		{
			continue;
		}

		ShopItem->UpdateData(Character->InventoryManager);
	}
}

void UShopWidget::ShopClosed()
{
	PopupManager::Instance->ClosePopup();
}
