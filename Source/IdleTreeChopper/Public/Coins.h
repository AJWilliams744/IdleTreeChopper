// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"

/**
 * 
 */
class IDLETREECHOPPER_API Coins : public InventoryItem
{
public:
	Coins();
	~Coins();

	std::string Name = "Coins";
};
