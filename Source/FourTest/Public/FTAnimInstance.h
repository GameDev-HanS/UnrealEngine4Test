// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class AFTCharacter* CharOwner;	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	float Garo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	float Sero;
};
