// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "FTCharacter.generated.h"

UCLASS()
class FOURTEST_API AFTCharacter : public ACharacter
{
	GENERATED_BODY()

public :
	// Sets default values for this character's properties
	AFTCharacter();

protected :
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

public :
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent*	ArmComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent*		CamComponent;

private :
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float					ArmLength = { 500.f };
};
