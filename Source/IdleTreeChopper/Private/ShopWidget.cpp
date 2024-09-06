// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopWidget.h"

#include "PopupManager.h"
#include "Components/Button.h"

void UShopWidget::NativeConstruct()
{
	Super::NativeConstruct();
	UE_LOG(LogTemp, Warning, TEXT("Shop Wait SetupClosed"));

	ExitButton->OnClicked.AddDynamic(this, &UShopWidget::ShopClosed);
}

void UShopWidget::ShopClosed()
{
	UE_LOG(LogTemp, Warning, TEXT("Shop Wait Closed"));
	PopupManager::Instance->ClosePopup();
}
