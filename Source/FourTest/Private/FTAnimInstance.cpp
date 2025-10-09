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
		Garo = CharOwner->GetHorizontal();
		Sero = CharOwner->GetVertical();
	}

	UE_LOG(LogTemp, Warning, TEXT("Garo : %.2f, Sero : %.2f"), Garo, Sero);
}
