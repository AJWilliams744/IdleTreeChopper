// Fill out your copyright notice in the Description page of Project Settings.


#include "Popup.h"
#include "Components/Button.h"
#include "PopupManager.h"
#include "Kismet/GameplayStatics.h"

void UPopup::NativeConstruct()
{
	Super::NativeConstruct();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	Character = PlayerController->GetCharacter();

	ExitButton->OnClicked.AddDynamic(this, &UPopup::ShopClosed);
}

void UPopup::ShopClosed()
{
	PopupManager::Instance->ClosePopup();
}
