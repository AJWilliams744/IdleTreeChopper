// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Popup.h"
#include "Blueprint/UserWidget.h"
#include "ShopWidget.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UShopWidget : public UPopup
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UUniformGridPanel* SellGrid;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UUniformGridPanel* BuyGrid;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* ExitButton;
};
