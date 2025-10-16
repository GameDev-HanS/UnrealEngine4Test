// Fill out your copyright notice in the Description page of Project Settings.


#include "FTEnemyController.h"

#include "NavigationSystem.h"
#include "FourTest/FourTest.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AFTEnemyController::AFTEnemyController()
{
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UBlackboardData>	EnemyBD(TEXT("BlackboardData'/Game/AI/BD_Enemy.BD_Enemy'"));
	static ConstructorHelpers::FObjectFinder<UBehaviorTree>		EnemyBT(TEXT("BehaviorTree'/Game/AI/BT_Enemy.BT_Enemy'"));

	BlackboardEnemy		= CreateDefaultSubobject<UBlackboardData>(TEXT("BLACKBOARD"));
	BehaviorTreeEnemy	= CreateDefaultSubobject<UBehaviorTree>(TEXT("BehaviorTree"));
	
	if (EnemyBD.Succeeded())
	{
		BlackboardEnemy = EnemyBD.Object;
	}

	if (EnemyBT.Succeeded())
	{
		BehaviorTreeEnemy = EnemyBT.Object;
	}
}

void AFTEnemyController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// GetWorld()->GetTimerManager().SetTimer(MoveTimer,
	// 	this, &AFTEnemyController::MoveRandomLocation,
	// 	2.f, true);

	if (UseBlackboard(BlackboardEnemy, Blackboard))
	{
		Blackboard->InitializeBlackboard(*BlackboardEnemy);

		Blackboard->SetValueAsFloat(TEXT("MoveRange"), 1000.f);
		
		// AI Controller의 Blackboard 멤버
		RunBehaviorTree(BehaviorTreeEnemy);
	}
}

void AFTEnemyController::OnUnPossess()
{
	Super::OnUnPossess();

	//GetWorld()->GetTimerManager().ClearTimer(MoveTimer);
}
