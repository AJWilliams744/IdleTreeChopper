// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Coins.h"
#include "FirstPersonCharacter.h"
#include "IdleChopperMode.h"
#include "Wood.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "UIWidget.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UUIWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* Crosshair;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* coinText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* woodText;

	void UpdateInfo(AFirstPersonCharacter* Character);

private:
	UWood* Wood = nullptr;
	UCoins* Coins = nullptr;
};
