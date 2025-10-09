// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FTAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class FOURTEST_API UFTAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected :
	virtual void NativeInitializeAnimation()				override;
	virtual void NativeUpdateAnimation(float DeltaSeconds)	override;

private :
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, meta = (AllowPrivateAccess = true))
	TWeakObjectPtr<APawn> OwnerPawn;	
};
