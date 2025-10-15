// Fill out your copyright notice in the Description page of Project Settings.


#include "StatComponent.h"

// Sets default values for this component's properties
UStatComponent::UStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Ammo = MaxAmmo;
}

void UStatComponent::SetAmmo(int32 NewAmmo)
{
	Ammo = NewAmmo;
	OnChangeAmmo.Broadcast(NewAmmo);
}

void UStatComponent::SetMaxAmmo(int32 NewMaxAmmo)
{
	MaxAmmo = NewMaxAmmo;
}

// Called when the game starts
void UStatComponent::BeginPlay()
{
	Super::BeginPlay();

	OnChangeAmmo.Broadcast(Ammo);
}

// Called every frame
void UStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

