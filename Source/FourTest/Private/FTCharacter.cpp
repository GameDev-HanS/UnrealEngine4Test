// Fill out your copyright notice in the Description page of Project Settings.


#include "FTCharacter.h"

// Sets default values
AFTCharacter::AFTCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ArmComponent	= CreateDefaultSubobject<USpringArmComponent>(TEXT("COM_ARM"));
	ArmComponent->SetupAttachment(GetCapsuleComponent());
	
	CamComponent	= CreateDefaultSubobject<UCameraComponent>(TEXT("COM_CAM"));
	CamComponent->SetupAttachment(ArmComponent);
	
	ArmComponent->TargetArmLength = ArmLength;

	constexpr float CapsuleHeight = 88.f;
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -CapsuleHeight));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
}

void AFTCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

// Called when the game starts or when spawned
void AFTCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AFTCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Called every frame
void AFTCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFTCharacter::SetVertical(float Value)
{
	Vertical = Value;
	if (bRun == false)
	{
		Vertical *= 0.5f;
	}
}

void AFTCharacter::SetHorizontal(float Value)
{
	Horizontal = Value;
	if (bRun == false)
	{
		Horizontal *= 0.5f;
	}
}
