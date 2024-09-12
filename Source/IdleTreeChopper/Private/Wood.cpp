// Fill out your copyright notice in the Description page of Project Settings.


#include "Wood.h"

FString UWood::Name = TEXT("Wood");

FString UWood::GetTextureName()
{
    return "/Script/Engine.Texture2D'/Game/CraftResourcesIcons/Textures/Tex_wood_03_b.Tex_wood_03_b'";
}

FString UWood::GetName()
{
    return Name;
}
