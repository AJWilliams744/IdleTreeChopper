// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyHUD.h"
#include "Popup.h"

/**
 * 
 */
class IDLETREECHOPPER_API PopupManager
{
public:
	PopupManager(AMyHUD* Hud);
	~PopupManager();

	void ShowPopup(TSubclassOf<UPopup> PopupClass);

	static PopupManager* Instance;

private:
	AMyHUD* Hud;
	bool showingPopup;
};
