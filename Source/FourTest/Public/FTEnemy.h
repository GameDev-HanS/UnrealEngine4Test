// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FTEnemy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChange, float, Ratio);

UCLASS()
class FOURTEST_API AFTEnemy : public ACharacter
{
	GENERATED_BODY()

public :
	// Sets default values for this character's properties
	AFTEnemy();

protected :
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public :	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

public :
	UPROPERTY(BlueprintAssignable, Category = "Health")
	FOnHealthChange	OnChangeHealth;

public :
	void GetDamaged(float Damage);
	
private :
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	class UWidgetComponent*	HealthWidget;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	float	Health		= 100.f;
	
	UPROPERTY(VisibleAnywhere, Category = "Health")
	float	MaxHealth	= 100.f;
};
