// Fill out your copyright notice in the Description page of Project Settings.


#include "Coins.h"

FString UCoins::Name = TEXT("Coins");

FString UCoins::GetTextureName()
{
    return "/Script/Engine.Texture2D'/Game/CraftResourcesIcons/Textures/Tex_spare_parts_11_b.Tex_spare_parts_11_b'";
}

FString UCoins::GetName()
{
    return Name;
}
