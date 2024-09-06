// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"

#include "IDamage.h"
#include "InteractInterface.h"
#include "MyHUD.h"
#include "UIWidget.h"
#include "Camera/CameraComponent.h"
#include "Components/TextBlock.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

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

	InventoryManager = NewObject<UInventoryManager>();
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AttackHeld)
	{
		AActor* HitActor = nullptr;
		if (RayCastCamera(HitActor))
		{
			if (IIDamage* damage = Cast<IIDamage>(HitActor))
			{
				damage->Hit(this);
			}
		}
	}
}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFirstPersonCharacter::Jump);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AFirstPersonCharacter::SprintOn);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFirstPersonCharacter::SprintOff);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AFirstPersonCharacter::Interact);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AFirstPersonCharacter::AttackOn);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &AFirstPersonCharacter::AttackOff);

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

void AFirstPersonCharacter::AttackOn()
{
	AttackHeld = true;
}

void AFirstPersonCharacter::AttackOff()
{
	AttackHeld = false;
}

void AFirstPersonCharacter::Interact()
{
	AActor* HitActor = nullptr;
	if (RayCastCamera(HitActor))
	{
		if (IInteractInterface* Interact = Cast<IInteractInterface>(HitActor))
		{
			Interact->Interact(this);
		}
	}
}

bool AFirstPersonCharacter::RayCastCamera(AActor*& HitActor) const
{
	FHitResult Hit;

	FVector TraceStart = Camera->GetComponentLocation();
	FVector TraceEnd = TraceStart + Camera->GetForwardVector() * 150.0f;

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByChannel(Hit, TraceStart, TraceEnd, TraceChannelProperty, QueryParams);

	HitActor = Hit.GetActor();
	if (Hit.bBlockingHit && IsValid(HitActor))
	{
		return true;
	}

	return false;
}
