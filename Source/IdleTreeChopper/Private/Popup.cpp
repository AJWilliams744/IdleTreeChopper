// Fill out your copyright notice in the Description page of Project Settings.


#include "Popup.h"

#include "Kismet/GameplayStatics.h"

void UPopup::NativeConstruct()
{
	Super::NativeConstruct();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	Character = Cast<AFirstPersonCharacter>(PlayerController->GetCharacter());
}
