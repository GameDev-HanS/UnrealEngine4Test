// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "FTHealthWidget.generated.h"

/**
 * 
 */
UCLASS()
class FOURTEST_API UFTHealthWidget : public UUserWidget
{
	GENERATED_BODY()

public :
	UFUNCTION(BlueprintCallable)
	void SetHealthRatio(float Ratio);

private :
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true, BindWidget))
	class UProgressBar* PB_Health;
};
