// Fill out your copyright notice in the Description page of Project Settings.


#include "FTController.h"
#include "FTCharacter.h"

AFTController::AFTController()
{
	
}

void AFTController::BeginPlay()
{
	Super::BeginPlay();

	CharPossess = Cast<AFTCharacter>(GetPawn());
}

void AFTController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	CharPossess = Cast<AFTCharacter>(InPawn);
}

void AFTController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("Run"), IE_Pressed, this,  &AFTController::OnKeyPressedRun);
	InputComponent->BindAction(TEXT("Run"), IE_Released, this,  &AFTController::OnKeyReleasedRun);
	InputComponent->BindAction(TEXT("Jump"), IE_Pressed, this,  &AFTController::OnKeyPressedJump);
	
	InputComponent->BindAxis(TEXT("MoveForward"), this, &AFTController::OnMoveForward);
	InputComponent->BindAxis(TEXT("MoveRight"), this, &AFTController::OnMoveRight);

	InputComponent->BindAxis(TEXT("Turn"), this, &AFTController::OnMouseMoveX);
}

void AFTController::OnKeyPressedRun()
{
	if (IsValid(CharPossess) == false)
		return;
	
	CharPossess->SetRun(true);
}

void AFTController::OnKeyReleasedRun()
{
	if (IsValid(CharPossess) == false)
		return;
	
	CharPossess->SetRun(false);
}

void AFTController::OnKeyPressedJump()
{
	if (IsValid(CharPossess) == false)
		return;
	
	CharPossess->Jump();
}

void AFTController::OnMoveForward(float Value)
{
	if (IsValid(CharPossess) == false)
		return;

	if (CharPossess->GetMovementComponent()->IsFalling() || CharPossess->GetLanding())
		return;
	
	CharPossess->SetVertical(Value);
	
	CharPossess->AddMovementInput(CharPossess->GetActorForwardVector(),
		CharPossess->GetVertical());
}

void AFTController::OnMoveRight(float Value)
{
	if (IsValid(CharPossess) == false)
		return;

	if (CharPossess->GetMovementComponent()->IsFalling() || CharPossess->GetLanding())
		return;
	
	CharPossess->SetHorizontal(Value);

	CharPossess->AddMovementInput(CharPossess->GetActorRightVector(),
		CharPossess->GetHorizontal());
}

void AFTController::OnMouseMoveX(float Value)
{
	if (IsValid(CharPossess) == false)
		return;

	if (CharPossess->GetMovementComponent()->IsFalling() || CharPossess->GetLanding())
		return;

	CharPossess->AddControllerYawInput(Value);
}
