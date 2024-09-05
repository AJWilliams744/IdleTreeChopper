// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IDamage.h"
#include "InteractInterface.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Tree.generated.h"

UCLASS()
class IDLETREECHOPPER_API ATree : public AActor, public IIDamage
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* Box;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth = 2;

	virtual void Hit(AFirstPersonCharacter* Character) override;

private:
	float Health;
};
