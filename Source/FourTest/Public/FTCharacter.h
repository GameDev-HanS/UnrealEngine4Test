// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Character.h"
#include "FTCharacter.generated.h"

UENUM()
enum class EControlMode
{
	GTA,
	DIABLO,
};

UCLASS()
class FOURTEST_API AFTCharacter : public ACharacter
{
	GENERATED_BODY()

public :
	// Sets default values for this character's properties
	AFTCharacter();

protected :
	virtual void PostInitializeComponents() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay()				override;

public : 
	virtual void Tick(float DeltaTime)		override;

public :
	bool	GetRun()		const	{ return bRun;			}
	float	GetVertical()	const	{ return Vertical;		}
	float	GetHorizontal()	const	{ return Horizontal;	}
	bool	GetLanding()	const	{ return bLanding;		}
	
public :
	UFUNCTION(BlueprintCallable)
	void SetRun(bool bValue)		{ bRun = bValue;	}

	UFUNCTION(BlueprintCallable)
	void SetVertical(float Value);

	UFUNCTION(BlueprintCallable)
	void SetHorizontal(float Value);

	UFUNCTION(BlueprintCallable)
	void SetLanding(bool bValue)	{ bLanding = bValue;	}

	void Attack();

	void SetControllMode(EControlMode NewControlMode);
	
private :
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Control, meta = (AllowPrivateAccess = "true"))
	bool bRun			= { false };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Control, meta = (AllowPrivateAccess = "true"))
	bool bLanding		= { false };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Control, meta = (AllowPrivateAccess = "true"))
	float Vertical		= { 0.f };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Control, meta = (AllowPrivateAccess = "true"))
	float Horizontal	= { 0.f };
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent*	ArmComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent*		CamComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stat, meta = (AllowPrivateAccess = "true"))
	class UStatComponent*	StatComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float					ArmLength = { 500.f };

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AFTProjectile> ProjectileClass;

	UPROPERTY(VisibleAnywhere, Category = ControllMode)
	EControlMode ControlMode = { EControlMode::GTA };
};