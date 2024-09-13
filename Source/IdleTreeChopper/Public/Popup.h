// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Popup.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API UPopup : public UUserWidget
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void NativeConstruct() override;

public:
	UPROPERTY()
	ACharacter* Character;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* ExitButton;

private:
	UFUNCTION()
	void ShopClosed();
};
