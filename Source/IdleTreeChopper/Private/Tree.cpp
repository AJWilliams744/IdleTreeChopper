// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree.h"

#include "Wood.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATree::ATree()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a new SceneComponent if you don't have one
	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	// Set the SceneComponent as the RootComponent
	RootComponent = SceneComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ATree::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
}

// Called every frame
void ATree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATree::Hit(AFirstPersonCharacter* Character)
{
	float deltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

	UE_LOG(LogTemp, Warning, TEXT("Hit"));

	Health -= deltaTime;

	if (Health <= 0)
	{
		Character->InventoryManager->AddItem(UWood::StaticClass(), 1);
		Health = MaxHealth;
	}
}
