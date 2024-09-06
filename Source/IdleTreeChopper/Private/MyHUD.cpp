// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

#include "IdleChopperMode.h"
#include "PopupManager.h"
#include "Kismet/GameplayStatics.h"

void AMyHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Character)
	{
		Character = Cast<AFirstPersonCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetCharacter());
	}

	gameUI->UpdateInfo(Character);
}

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AIdleChopperMode>(GetWorld()->GetAuthGameMode());
}

void AMyHUD::CreatePopupManager()
{
	MyPopupManager = new PopupManager(this);
}
