// Fill out your copyright notice in the Description page of Project Settings.


#include "Shop.h"

#include "PopupManager.h"
#include "Components/BoxComponent.h"

// Sets default values
AShop::AShop()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AShop::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AShop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShop::Interact(AFirstPersonCharacter* Character)
{
	PopupManager::Instance->ShowPopup(PopupClass);
}
