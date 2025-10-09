// Fill out your copyright notice in the Description page of Project Settings.


#include "FTController.h"

AFTController::AFTController()
{
	
}

void AFTController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("Walk"), IE_Pressed, this,  &AFTController::Set_Walk);
	InputComponent->BindAction(TEXT("Walk"), IE_Released, this,  &AFTController::Set_NotWalk);
	
	InputComponent->BindAction(TEXT("Run"), IE_Pressed, this,  &AFTController::Set_Run);
	InputComponent->BindAction(TEXT("Run"), IE_Released, this,  &AFTController::Set_NotRun);
}