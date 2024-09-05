// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IdleChopperMode.h"
#include "MyHUD.h"
#include "GameFramework/Character.h"
#include "FirstPersonCharacter.generated.h"

UCLASS()
class IDLETREECHOPPER_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category="Collision", BlueprintReadWrite)
	TEnumAsByte<ECollisionChannel> TraceChannelProperty = ECC_Pawn;

	AIdleChopperMode* GameMode;

protected:
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	void MoveForward(float val);
	void MoveRight(float val);

	void TurnCamera(float val);
	void LookUp(float val);

	void SprintOn();
	void SprintOff();

	void AttackOn();
	void AttackOff();

	void Interact();

	bool RayCastCamera(AActor*& HitActor) const;

private:
	float forwardSpeed;
	UCharacterMovementComponent* MovementComponent;
	bool AttackHeld;

	AMyHUD* Hud;
};
