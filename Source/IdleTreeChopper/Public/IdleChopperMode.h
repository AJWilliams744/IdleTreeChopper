// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "IdleChopperMode.generated.h"

/**
 * 
 */
UCLASS()
class IDLETREECHOPPER_API AIdleChopperMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int coins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int wood;
};
