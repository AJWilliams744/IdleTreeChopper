// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IDamage.h"
#include "InteractInterface.h"
#include "Wood.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RespawnRate = 150;

	virtual void Hit(AFirstPersonCharacter* Character) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)

	float Health;

	UFUNCTION(BlueprintImplementableEvent, Category = "Events")
	void OnTreeDissolved();

	UFUNCTION(BlueprintImplementableEvent, Category = "Events")
	void OnTreeSpawn();

private:
	bool Dead;
	float RespawnTime;
	void SetTreeVisibility(bool Visibility);
};
