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

	if (Dead)
	{
		RespawnTime += DeltaTime;
		if (RespawnTime > RespawnRate)
		{
			Dead = false;
			Health = MaxHealth;
			RespawnTime = 0;
			SetTreeVisibility(true);
		}
	}
}

void ATree::Hit(AFirstPersonCharacter* Character)
{
	if (Dead) return;

	float deltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

	Health -= deltaTime * Character->StatsManager->GetStatValue(EPlayerStat::AttackDamage);

	if (Health <= 0)
	{
		Character->InventoryManager->AddItem(UWood::StaticClass(), 1);
		Dead = true;
		SetTreeVisibility(false);
	}
}

void ATree::SetTreeVisibility(const bool Visibility)
{
	if (!Visibility)
	{
		OnTreeDissolved();
	}
	else
	{
		OnTreeSpawn();
	}

	StaticMesh->SetCollisionEnabled(Visibility ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);
}
