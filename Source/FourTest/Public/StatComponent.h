// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FOURTEST_API UStatComponent : public UActorComponent
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeAmmo, float, Ammo);
	
public :	
	// Sets default values for this component's properties
	UStatComponent();

protected :
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public :
	int32 GetAmmo()		const { return Ammo; }
	int32 GetMaxAmmo()	const { return MaxAmmo; }

	void SetAmmo(int32 NewAmmo);
	void SetMaxAmmo(int32 NewMaxAmmo);

public :
	UPROPERTY(BlueprintAssignable, Category = "StatComponent")
	FOnChangeAmmo OnChangeAmmo;
	
private :
	UPROPERTY(VisibleAnywhere, Category = "StatComponent")
	int32 Ammo;

	UPROPERTY(VisibleAnywhere, Category = "StatComponent")
	int32 MaxAmmo	= 50;
};
