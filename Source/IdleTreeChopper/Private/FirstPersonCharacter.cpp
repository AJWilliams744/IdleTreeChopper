// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;

	MovementComponent = GetCharacterMovement();
	forwardSpeed = MovementComponent->MaxWalkSpeed;
}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFirstPersonCharacter::Jump);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AFirstPersonCharacter::SprintOn);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFirstPersonCharacter::SprintOff);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFirstPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFirstPersonCharacter::MoveRight);

	PlayerInputComponent->BindAxis("TurnCamera", this, &AFirstPersonCharacter::TurnCamera);
	PlayerInputComponent->BindAxis("LookUp", this, &AFirstPersonCharacter::LookUp);
}

void AFirstPersonCharacter::MoveForward(float val)
{
	FVector Direction = GetActorForwardVector();
	AddMovementInput(Direction, val);
}

void AFirstPersonCharacter::MoveRight(float val)
{
	FVector Direction = GetActorRightVector();
	AddMovementInput(Direction, val);
}

void AFirstPersonCharacter::TurnCamera(float val)
{
	AddControllerYawInput(val);
}

void AFirstPersonCharacter::LookUp(float val)
{
	AddControllerPitchInput(val);
}

void AFirstPersonCharacter::SprintOn()
{
	MovementComponent->MaxWalkSpeed = forwardSpeed * 2;
}

void AFirstPersonCharacter::SprintOff()
{
	MovementComponent->MaxWalkSpeed = forwardSpeed;
}
