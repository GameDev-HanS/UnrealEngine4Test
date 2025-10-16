// Fill out your copyright notice in the Description page of Project Settings.


#include "FTProjectile.h"

#include "FTCharacter.h"
#include "FourTest/FourTest.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AFTProjectile::AFTProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent		= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent		= MeshComponent;
	
	BoxComponent		= CreateDefaultSubobject<UBoxComponent>(TEXT("BOX"));
	BoxComponent->SetupAttachment(MeshComponent);
	
	ProjMoveComponet	= CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MOVEMENT"));
}

// Called when the game starts or when spawned
void AFTProjectile::BeginPlay()
{
	Super::BeginPlay();

}

void AFTProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AFTProjectile::OnOverlapBegin);
}

// Called every frame
void AFTProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, 0, RotateSpeed * DeltaTime));
}

void AFTProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(FourTest, Warning, TEXT("OnOverlapBegin"));

	auto Player = Cast<AFTCharacter>(OtherActor);

	if (Player == nullptr)
	{
		SetActorEnableCollision(false);
		SetActorHiddenInGame(true);
		Destroy();
	}
}

