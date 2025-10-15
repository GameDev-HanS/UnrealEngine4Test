// Fill out your copyright notice in the Description page of Project Settings.



#include "FTCharacter.h"
#include "FTProjectile.h"
#include "StatComponent.h"
#include "Engine/SkeletalMeshSocket.h"

// Sets default values
AFTCharacter::AFTCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ArmComponent	= CreateDefaultSubobject<USpringArmComponent>(TEXT("COM_ARM"));
	ArmComponent->SetupAttachment(GetCapsuleComponent());
	
	CamComponent	= CreateDefaultSubobject<UCameraComponent>(TEXT("COM_CAM"));
	CamComponent->SetupAttachment(ArmComponent);

	StatComponent	= CreateDefaultSubobject<UStatComponent>(TEXT("STAT"));
	
	ArmComponent->TargetArmLength = ArmLength;

	constexpr float CapsuleHeight = 88.f;
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -CapsuleHeight));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	static ConstructorHelpers::FClassFinder<AFTProjectile> ProjectileBPClass(TEXT("Blueprint'/Game/Blueprints/BP_FTBullet.BP_FTBullet_C'"));

	if (!ensure(ProjectileBPClass.Succeeded()))
		return;
	
	ProjectileClass = ProjectileBPClass.Class;

	SetControllMode(EControlMode::GTA);
}

void AFTCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

// Called when the game starts or when spawned
void AFTCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AFTCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Called every frame
void AFTCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFTCharacter::SetVertical(float Value)
{
	Vertical = Value;
	if (bRun == false)
	{
		Vertical *= 0.5f;
	}
}

void AFTCharacter::SetHorizontal(float Value)
{
	Horizontal = Value;
	if (bRun == false)
	{
		Horizontal *= 0.5f;
	}
}

void AFTCharacter::Attack()
{
	FName ProjectileSocket(TEXT("Muzzle_Front_NoAnimation"));
	
	class USkeletalMeshSocket const* MuzzleSocket = GetMesh()->GetSocketByName(ProjectileSocket);

	auto SocketTransform = GetMesh()->GetSocketTransform(ProjectileSocket);

	const FActorSpawnParameters SpawnParameters;
	
	AFTProjectile* Porjectile = GetWorld()->SpawnActor<AFTProjectile>(
		ProjectileClass,
		SocketTransform.GetLocation(),
		GetActorRotation());

	UE_LOG(LogTemp, Warning, TEXT("Attack!"));
}

void AFTCharacter::SetControllMode(EControlMode NewControlMode)
{
	if (ControlMode == NewControlMode) return;

	GetCharacterMovement()->bOrientRotationToMovement	= true;
	GetCharacterMovement()->RotationRate				= FRotator(0.f, 720.f, 0.f);		
	
	switch(NewControlMode)
	{
	case EControlMode::GTA :
		{
			ArmLength = 500.f;
			ArmComponent->TargetArmLength = ArmLength;

			ArmComponent->SetRelativeRotation(FRotator::ZeroRotator);

			ArmComponent->bUsePawnControlRotation	= true;	// 컨트롤러 회전에 따라간다.
			ArmComponent->bInheritPitch				= true; // 컨트롤러 회전 값을 적용한다.
			ArmComponent->bInheritYaw				= true;
			ArmComponent->bInheritRoll				= true;
			ArmComponent->bDoCollisionTest			= true;
			bUseControllerRotationYaw				= false; // 컨트롤러 Z 축 회전
		}
		break;
	case EControlMode::DIABLO :
		{
			ArmLength = 800.f;
			ArmComponent->TargetArmLength = ArmLength;
			
			ArmComponent->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
			ArmComponent->bUsePawnControlRotation	= false;	// 컨트롤러 회전에 따라간다.
			ArmComponent->bInheritPitch				= false; // 컨트롤러 회전 값을 적용한다.
			ArmComponent->bInheritYaw				= false;
			ArmComponent->bInheritRoll				= false;
			ArmComponent->bDoCollisionTest			= false;
			bUseControllerRotationYaw				= true; // 컨트롤러 Z 축 회전
		}
		break;
	default :
		break;
	}

	ControlMode = NewControlMode;
}
