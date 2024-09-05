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
	void ClosePopup();

	static PopupManager* Instance;

private:
	AMyHUD* Hud;
	bool showingPopup = false;
	UPopup* currentPopup = nullptr;

	void LockUserCameraAndCursor(bool value, APlayerController* PlayerController);
};
