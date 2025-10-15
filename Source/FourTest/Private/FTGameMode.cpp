// Fill out your copyright notice in the Description page of Project Settings.


#include "FTGameMode.h"
#include "FourTest/FourTest.h"
#include "FTCharacter.h"
#include "FTController.h"
#include "FTHUD.h"

AFTGameMode::AFTGameMode()
{
	static ConstructorHelpers::FClassFinder<AFTCharacter>	BPPawnClass(TEXT("Blueprint'/Game/Blueprints/BP_FTCharacter.BP_FTCharacter_C'"));
	static ConstructorHelpers::FClassFinder<AFTHUD>			PlayerHudClass(TEXT("Class'/Script/FourTest.FTHUD'"));		

	if (BPPawnClass.Succeeded())
	{
		DefaultPawnClass = BPPawnClass.Class;
	}

	if (PlayerHudClass.Succeeded())
	{
		HUDClass = PlayerHudClass.Class;
	}

	PlayerControllerClass = AFTController::StaticClass();
}

void AFTGameMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UE_LOG(FourTest, Warning, TEXT("AFTGameMode::PostInitializeComponents"));
}

void AFTGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	UE_LOG(FourTest, Warning, TEXT("AFTGameMode::PostLogin"));
}

void AFTGameMode::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(FourTest, Warning, TEXT("AFTGameMode::BeginPlay"));
}
