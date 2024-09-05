// Fill out your copyright notice in the Description page of Project Settings.


#include "PopupManager.h"

#include "MyHUD.h"
#include "Kismet/GameplayStatics.h"

PopupManager* PopupManager::Instance = nullptr;

PopupManager::PopupManager(AMyHUD* Hud)
{
	this->Hud = Hud;
	Instance = this;
}

PopupManager::~PopupManager()
{
}


void PopupManager::ShowPopup(TSubclassOf<UPopup> PopupClass)
{
	if (showingPopup) return;
	showingPopup = true;
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(Hud->GetWorld(), 0);
	UPopup* Popup = CreateWidget<UPopup>(PlayerController, PopupClass);

	FInputModeGameAndUI Mode;
	Mode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	Mode.SetHideCursorDuringCapture(false);
	PlayerController->SetInputMode(Mode);

	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = true;
		PlayerController->bEnableClickEvents = true;
		PlayerController->bEnableMouseOverEvents = true;
		PlayerController->SetIgnoreLookInput(true); // Ignore camera movements
		PlayerController->SetIgnoreMoveInput(true); // Ignore movement inputs
	}

	Popup->AddToViewport(9999); // Z-order, this just makes it render on the very top.

	UE_LOG(LogTemp, Warning, TEXT("Popup showing"));
}
