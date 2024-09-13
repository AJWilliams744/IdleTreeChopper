// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Popup.h"
#include "ShopWidget.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UShopWidget : public UPopup
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void NativeConstruct() override;

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UUniformGridPanel* SellGrid;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UUniformGridPanel* BuyGrid;
};
