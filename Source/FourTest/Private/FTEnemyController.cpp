// Fill out your copyright notice in the Description page of Project Settings.


#include "FTEnemyController.h"

#include "NavigationSystem.h"
#include "FourTest/FourTest.h"
#include "Kismet/GameplayStatics.h"

AFTEnemyController::AFTEnemyController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AFTEnemyController::MoveRandomLocation()
{
	APawn* ControlledPawn = GetPawn();

	if (ControlledPawn == nullptr)
		return;

	UE_LOG(FourTest, Warning, TEXT("GetPawn()"));
	
	UNavigationSystemV1* NavSystem  = UNavigationSystemV1::GetCurrent(GetWorld());

	if (NavSystem == nullptr)
		return;
	
	UE_LOG(FourTest, Warning, TEXT("Find NavSystem"));

	StartLocation = ControlledPawn->GetActorLocation();
	
	FNavLocation NavLocation;

	bool bSet;
	do
	{
		bSet = NavSystem->GetRandomPointInNavigableRadius(
		StartLocation,
		MoveRange,
		NavLocation);
	}
	while (bSet == false);

	UE_LOG(FourTest, Warning, TEXT("Find Place To Go"));
	
	MoveToLocation(NavLocation);

	// Draw Debug
	UKismetSystemLibrary::DrawDebugLine(
		GetWorld(),
		StartLocation,
		NavLocation,
		FColor::Red,
		2.f,
		10.f);

	UKismetSystemLibrary::DrawDebugSphere(
	GetWorld(),
	StartLocation, 100, 24, FColor::Black, 2.f, 10.f);

	UKismetSystemLibrary::DrawDebugSphere(
	GetWorld(),
	NavLocation, 100, 24, FColor::Black, 2.f, 10.f);
}

void AFTEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	GetWorld()->GetTimerManager().SetTimer(MoveTimer,
		this, &AFTEnemyController::MoveRandomLocation,
		2.f, true);
}

void AFTEnemyController::OnUnPossess()
{
	Super::OnUnPossess();

	GetWorld()->GetTimerManager().ClearTimer(MoveTimer);
}
