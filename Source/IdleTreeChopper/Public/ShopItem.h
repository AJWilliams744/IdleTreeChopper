// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopItem.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UShopItem : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* Button;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* ButtonText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* PriceText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* Picture;
};
