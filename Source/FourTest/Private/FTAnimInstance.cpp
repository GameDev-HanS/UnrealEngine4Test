// Fill out your copyright notice in the Description page of Project Settings.


#include "FTAnimInstance.h"

void UFTAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	OwnerPawn = TryGetPawnOwner();
}

void UFTAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}
