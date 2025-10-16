// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FTBTTask_FindRandomMove.generated.h"

/**
 * 
 */
UCLASS()
class FOURTEST_API UFTBTTask_FindRandomMove : public UBTTaskNode
{
	GENERATED_BODY()

public :
	UFTBTTask_FindRandomMove();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Comp, uint8* NodeMemory) override;
	
};
