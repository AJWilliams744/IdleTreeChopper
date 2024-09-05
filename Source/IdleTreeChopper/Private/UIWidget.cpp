// Fill out your copyright notice in the Description page of Project Settings.


#include "UIWidget.h"

#include "Components/TextBlock.h"

void UUIWidget::UpdateInfo(AIdleChopperMode* GameMode)
{
	coinText->SetText(FText::AsNumber(GameMode->coins));
	woodText->SetText(FText::AsNumber(GameMode->wood));
}
