// Fill out your copyright notice in the Description page of Project Settings.


#include "FTBTTask_FindRandomMove.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "FourTest/FourTest.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

UFTBTTask_FindRandomMove::UFTBTTask_FindRandomMove()
{
	NodeName = TEXT("FindRandomLocation");
}

EBTNodeResult::Type UFTBTTask_FindRandomMove::ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory)
{
	 EBTNodeResult::Type Result = Super::ExecuteTask(Comp, NodeMemory);

	AAIController* Controller	= Comp.GetAIOwner();
	APawn* ControlledPawn		= Controller->GetPawn();
	
	if (ControlledPawn == nullptr)
		return EBTNodeResult::Failed;

	UE_LOG(FourTest, Warning, TEXT("GetPawn()"));
	
	UNavigationSystemV1* NavSystem  = UNavigationSystemV1::GetCurrent(GetWorld());

	if (NavSystem == nullptr)
		return EBTNodeResult::Failed;
	
	UE_LOG(FourTest, Warning, TEXT("Find NavSystem"));

	FVector StartLocation = ControlledPawn->GetActorLocation();
	
	FNavLocation NavLocation;

	float MoveRange = Comp.GetBlackboardComponent()->GetValueAsFloat(TEXT("MoveRange"));

	bool bSet;
	do
	{
		bSet = NavSystem->GetRandomPointInNavigableRadius(
		StartLocation,
		MoveRange,
		NavLocation);
	}
	while (bSet == false);

	Comp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("MoveLocation")), NavLocation);

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

	return EBTNodeResult::Succeeded;
}
