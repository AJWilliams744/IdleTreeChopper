// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIWidget.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API AMyHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UUIWidget* gameUI;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

private:
	AIdleChopperMode* GameMode;
};
