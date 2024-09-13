// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerStatsManager.h"
#include "StatsStruct.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatItem.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UPlayerStatItem : public UUserWidget
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
	EPlayerStat StatType;

	void UpdateData(UPlayerStatsManager* StatsManager);

	UFUNCTION()
	void ButtonClicked();
};
