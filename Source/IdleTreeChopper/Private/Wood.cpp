// Fill out your copyright notice in the Description page of Project Settings.


#include "Wood.h"

FString UWood::Name = TEXT("Wood");

FString UWood::GetTextureName()
{
	return "/Script/Engine.Texture2D'/Game/Textures/Wood.Wood";
}

FString UWood::GetName()
{
	return Name;
}
