// Fill out your copyright notice in the Description page of Project Settings.


#include "FTAnimInstance.h"

#include "FTCharacter.h"

void UFTAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	CharOwner = Cast<AFTCharacter>(TryGetPawnOwner());
}

void UFTAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (IsValid(CharOwner))
	{
		Garo		= CharOwner->GetHorizontal();
		Sero		= CharOwner->GetVertical();
		bIsFalling	= CharOwner->GetMovementComponent()->IsFalling();
	} 

	UE_LOG(LogTemp, Warning, TEXT("Garo : %.2f, Sero : %.2f, IsFalling : %d"), Garo, Sero, bIsFalling);
}

void UFTAnimInstance::AnimNotify_LandStart()
{
	if (IsValid(CharOwner) == false) return;

	CharOwner->SetLanding(true);

	CharOwner->SetHorizontal(0.f);
	CharOwner->SetVertical(0.f);
	
	UE_LOG(LogTemp, Warning, TEXT("Land Start"));
}

void UFTAnimInstance::AnimNotify_LandDone()
{
	if (IsValid(CharOwner) == false ) return;

	CharOwner->SetLanding(false);
	
	UE_LOG(LogTemp, Warning, TEXT("Land Done"));
}