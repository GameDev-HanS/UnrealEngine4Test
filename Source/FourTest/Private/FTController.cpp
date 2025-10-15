// Fill out your copyright notice in the Description page of Project Settings.


#include "FTController.h"
#include "FourTest/FourTest.h"
#include "FTCharacter.h"

AFTController::AFTController()
{
	
}

void AFTController::BeginPlay()
{
	Super::BeginPlay();

	CharPossess = Cast<AFTCharacter>(GetPawn());

	UE_LOG(FourTest, Warning, TEXT("AFTController::BeginPlay"));
}

void AFTController::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UE_LOG(FourTest, Warning, TEXT("AFTController::PostInitializeComponents"));
}

void AFTController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	CharPossess = Cast<AFTCharacter>(InPawn);

	UE_LOG(FourTest, Warning, TEXT("AFTController::OnPossess"));
}

void AFTController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("Run"), IE_Pressed, this,  &AFTController::OnKeyPressedRun);
	InputComponent->BindAction(TEXT("Run"), IE_Released, this,  &AFTController::OnKeyReleasedRun);
	InputComponent->BindAction(TEXT("Jump"), IE_Pressed, this,  &AFTController::OnKeyPressedJump);
	InputComponent->BindAction(TEXT("Attack"), IE_Pressed, this, &AFTController::OnKeyPressedAttack);
	
	InputComponent->BindAxis(TEXT("MoveForward"), this, &AFTController::OnMoveForward);
	InputComponent->BindAxis(TEXT("MoveRight"), this, &AFTController::OnMoveRight);

	InputComponent->BindAxis(TEXT("Turn"), this, &AFTController::OnMouseMoveX);
	InputComponent->BindAxis(TEXT("LookUp"), this, &AFTController::OnMouseMoveY);
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

void AFTController::OnKeyPressedAttack()
{
	if (IsValid(CharPossess) == false)
		return;

	CharPossess->Attack();
}

void AFTController::OnMoveForward(float Value)
{
	if (IsValid(CharPossess) == false)
		return;

	if (CharPossess->GetMovementComponent()->IsFalling() || CharPossess->GetLanding())
		return;
	
	CharPossess->SetVertical(Value);
	
	CharPossess->AddMovementInput(
			CharPossess->GetActorForwardVector(),
			CharPossess->GetVertical());

	// CharPossess->AddMovementInput(
	// 		FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X),
	// 		CharPossess->GetVertical());
}

void AFTController::OnMoveRight(float Value)
{
	if (IsValid(CharPossess) == false)
		return;

	if (CharPossess->GetMovementComponent()->IsFalling() || CharPossess->GetLanding())
		return;
	
	CharPossess->SetHorizontal(Value);

	CharPossess->AddMovementInput(
		CharPossess->GetActorRightVector(),
		CharPossess->GetHorizontal());
	
	// CharPossess->AddMovementInput(
	// 	FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y),
	// 	CharPossess->GetHorizontal());
}

void AFTController::OnMouseMoveX(float Value)
{
	if (IsValid(CharPossess) == false)
		return;

	if (CharPossess->GetMovementComponent()->IsFalling() || CharPossess->GetLanding())
		return;

	CharPossess->AddControllerYawInput(Value);		// Z 축 회전
}

void AFTController::OnMouseMoveY(float Value)
{
	if (IsValid(CharPossess) == false)
		return;

	CharPossess->AddControllerPitchInput(Value);	// Y 축 회전
}
