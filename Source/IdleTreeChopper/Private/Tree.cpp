// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ATree::ATree()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	Box = CreateDefaultSubobject<UBoxComponent>(FName("Box"));
	Box->SetBoxExtent(FVector(74.0f, 125.0f, 100.0f));
	Box->SetupAttachment(StaticMesh);
	Box->SetRelativeLocation(FVector(0.0f, 0.0f, -50.0f));
}

// Called when the game starts or when spawned
void ATree::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATree::Hit(AFirstPersonCharacter* Character)
{
	float deltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

	Health -= deltaTime;

	if (Health <= 0)
	{
		Character->GameMode->wood++;
		Health = MaxHealth;
	}
}
