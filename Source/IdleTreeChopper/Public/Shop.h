// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractInterface.h"
#include "Popup.h"
#include "GameFramework/Actor.h"
#include "Shop.generated.h"

UCLASS()
class IDLETREECHOPPER_API AShop : public AActor, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AShop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Popup")
	TSubclassOf<UPopup> PopupClass;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* Box;

	UPROPERTY()
	class UPopup* Popup;

	virtual void Interact(AFirstPersonCharacter* Character) override;
};
