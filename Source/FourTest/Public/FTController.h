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
	virtual void SetupInputComponent() override;

private :
	UFUNCTION()
	void Set_Walk()		{ bWalk = true;	}

	UFUNCTION()
	void Set_NotWalk()	{ bWalk = false;}

	UFUNCTION()
	void Set_Run()		{ bRun = true;	}

	UFUNCTION()
	void Set_NotRun()	{ bRun = false; }
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Control, meta = (AllowPrivateAccess = "true"))
	bool bWalk	= { false };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Control, meta = (AllowPrivateAccess = "true"))
	bool bRun	= { false };
};
