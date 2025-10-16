// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FTEnemyController.generated.h"

/**
 * 
 */
UCLASS()
class FOURTEST_API AFTEnemyController : public AAIController
{
	GENERATED_BODY()

public :
	AFTEnemyController();

public :
	void MoveRandomLocation();

protected :
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

private :
	FTimerHandle MoveTimer;

	FVector		 StartLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	float MoveRange = 1000.f;
};
