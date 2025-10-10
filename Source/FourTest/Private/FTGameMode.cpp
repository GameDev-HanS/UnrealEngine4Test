// Fill out your copyright notice in the Description page of Project Settings.


#include "FTGameMode.h"
#include "FTCharacter.h"
#include "FTController.h"

AFTGameMode::AFTGameMode()
{
	static ConstructorHelpers::FClassFinder<AFTCharacter>	BPPawnClass(TEXT("Blueprint'/Game/Blueprints/BP_FTCharacter.BP_FTCharacter_C'"));
	
	if (BPPawnClass.Succeeded())
	{
		DefaultPawnClass = BPPawnClass.Class;
	}

	PlayerControllerClass = AFTController::StaticClass();
}
