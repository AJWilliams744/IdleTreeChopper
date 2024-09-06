// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>

#include "CoreMinimal.h"

/**
 * 
 */
class IDLETREECHOPPER_API InventoryItem
{
public:
	InventoryItem();
	~InventoryItem();

	std::string Name = "Item";
	int Quantity;
};
