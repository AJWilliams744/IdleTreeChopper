// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

#include "IdleChopperMode.h"

void AMyHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	gameUI->UpdateInfo(GameMode);
}

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<AIdleChopperMode>(GetWorld()->GetAuthGameMode());
}
