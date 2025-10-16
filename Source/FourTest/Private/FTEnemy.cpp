// Fill out your copyright notice in the Description page of Project Settings.


#include "FTEnemy.h"
#include "FTHealthWidget.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "FourTest/FourTest.h"
#include "Kismet/GameplayStatics.h"
#include "FTEnemyController.h"

// Sets default values
AFTEnemy::AFTEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// UI
	HealthWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthWidget"));
	HealthWidget->SetupAttachment(RootComponent);
	
	ConstructorHelpers::FClassFinder<UFTHealthWidget> WBP_Health(TEXT("WidgetBlueprint'/Game/Blueprints/WBP_Health.WBP_Health_C'"));

	if (WBP_Health.Succeeded())
	{
		HealthWidget->SetWidgetClass(WBP_Health.Class);
		HealthWidget->SetDrawSize(FVector2D(100.f, 30.f));
	}

	// AI
	ConstructorHelpers::FClassFinder<AFTEnemyController> EnemyController(TEXT("Class'/Script/FourTest.FTEnemyController'"));

	if (EnemyController.Succeeded())
	{
		AIControllerClass	= EnemyController.Class;
		AutoPossessAI		= EAutoPossessAI::PlacedInWorldOrSpawned; // 월드에 배치 or 스폰 시 빙의
	}
}

// Called when the game starts or when spawned
void AFTEnemy::BeginPlay()
{
	Super::BeginPlay();

	UFTHealthWidget* CastWidget = Cast<UFTHealthWidget>(HealthWidget->GetUserWidgetObject());

	if (CastWidget)
	{
		OnChangeHealth.AddDynamic(CastWidget, &UFTHealthWidget::SetHealthRatio);
		UE_LOG(FourTest, Warning, TEXT("Bind Success"));
	}
}

void AFTEnemy::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	HealthWidget->SetRelativeLocation(FVector(0.f, 0.f, 130.f));
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AFTEnemy::OnOverlapBegin);
}

// Called every frame
void AFTEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (!PC || !HealthWidget) return;

	FVector CameraLocation;
	FRotator CameraRotation;
	PC->GetPlayerViewPoint(CameraLocation, CameraRotation);
	
	FVector Direction = CameraLocation - HealthWidget->GetComponentLocation();
	Direction.Z = 0;                
	Direction.Normalize(); 
	
	FRotator LookRotation = Direction.Rotation();
	HealthWidget->SetWorldRotation(LookRotation);
}

// Called to bind functionality to input
void AFTEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AFTEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GetDamaged(10.f);
}

void AFTEnemy::GetDamaged(float Damage)
{
	Health -= Damage;
	if (Health <= 0)
	{
		SetActorEnableCollision(false);
		SetActorHiddenInGame(true);
		Destroy();
	}

	OnChangeHealth.Broadcast(Health / MaxHealth);
}