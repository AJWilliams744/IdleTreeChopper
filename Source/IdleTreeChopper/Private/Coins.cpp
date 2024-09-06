// Fill out your copyright notice in the Description page of Project Settings.


#include "Coins.h"

FString UCoins::Name = TEXT("Coins");

FString UCoins::GetTextureName()
{
	return "/Script/Engine.Texture2D'/Game/Textures/Coins.Coins";
}

FString UCoins::GetName()
{
	return Name;
}
