// Fill out your copyright notice in the Description page of Project Settings.


#include "FTHealthWidget.h"
#include "FourTest/FourTest.h"

void UFTHealthWidget::SetHealthRatio(float Ratio)
{
	PB_Health->SetPercent(Ratio);
	UE_LOG(FourTest, Warning, TEXT("Change Percent"));
}
