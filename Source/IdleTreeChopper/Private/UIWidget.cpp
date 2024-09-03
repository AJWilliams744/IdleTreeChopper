// Fill out your copyright notice in the Description page of Project Settings.


#include "UIWidget.h"

#include "Components/TextBlock.h"

void UUIWidget::UpdateInfo(int coins, int wood)
{
	coinText->SetText(FText::AsNumber(coins));
	woodText->SetText(FText::AsNumber(wood));
}
