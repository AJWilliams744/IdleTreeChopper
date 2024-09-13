// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStats.h"

#include "FirstPersonCharacter.h"
#include "PlayerStatItem.h"
#include "Components/UniformGridPanel.h"

void UPlayerStats::NativeConstruct()
{
	Super::NativeConstruct();

	TArray<UWidget*> Children = StatsGrid->GetAllChildren();

	for (UWidget* Child : Children)
	{
		if (!Child) continue;

		UPlayerStatItem* ShopItem = Cast<UPlayerStatItem>(Child);
		if (!ShopItem)
		{
			continue;
		}

		ShopItem->UpdateData(Cast<AFirstPersonCharacter>(Character)->StatsManager);
	}
}
