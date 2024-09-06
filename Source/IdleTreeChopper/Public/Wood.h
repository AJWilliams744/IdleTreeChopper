// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"

/**
 * 
 */
class IDLETREECHOPPER_API Wood : public InventoryItem
{
public:
	Wood();
	~Wood();

	std::string Name = "Wood";
};
