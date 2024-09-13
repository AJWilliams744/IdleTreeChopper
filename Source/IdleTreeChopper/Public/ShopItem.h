// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "InventoryManager.h"
#include "Blueprint/UserWidget.h"
#include "ShopItem.generated.h"

class UPlayerStatsManager;
/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UShopItem : public UUserWidget
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void NativeConstruct() override;

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* Button;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* ButtonText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* NameText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* PriceText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* Picture;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* QuantityText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class TSubclassOf<UInventoryItem> ItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Buying;

	void UpdateData(UInventoryManager* InInventoryManager, UPlayerStatsManager* InStatsManager);

	UFUNCTION()
	void ButtonClicked();

private:
	UPROPERTY()
	UInventoryManager* InventoryManager;

	UPROPERTY()
	UPlayerStatsManager* StatsManager;

	UPROPERTY()
	UInventoryItem* Item;
};
