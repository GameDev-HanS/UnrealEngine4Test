// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FTController.generated.h"

/**
 * 
 */
UCLASS()
class FOURTEST_API AFTController : public APlayerController
{
	GENERATED_BODY()
	
public :
	AFTController();

protected :
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn)	override;
	virtual void SetupInputComponent()		override;

public :
	void OnKeyPressedRun();
	void OnKeyReleasedRun();
	void OnKeyPressedJump();
	
	void OnMoveForward(float Value);
	void OnMoveRight(float Value);
	void OnMouseMoveX(float Value);

private :
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class AFTCharacter* CharPossess;
};
