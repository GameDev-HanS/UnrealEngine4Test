// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FTStatWidget.generated.h"

/**
 * 
 */
UCLASS()
class FOURTEST_API UFTStatWidget : public UUserWidget
{
	GENERATED_BODY()
	
public :
	UFUNCTION(BlueprintCallable, Category = "UI")
	void SetTextBlock(const FText& Text);
	
private :
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlock;
};
