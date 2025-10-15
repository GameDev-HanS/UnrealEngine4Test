// Fill out your copyright notice in the Description page of Project Settings.


#include "FTStatWidget.h"
#include "Components/TextBlock.h"

void UFTStatWidget::SetTextBlock(const FText& Text)
{
	if (TextBlock)
		TextBlock->SetText(Text);
}
