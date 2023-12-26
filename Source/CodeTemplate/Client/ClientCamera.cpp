// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientCamera.h"
#include "../Manager/LogManager.h"
#include "../Manager/EventManager.h"

// Sets default values
AClientCamera::AClientCamera()
{
	// Set this character to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	SetCurrentLocation(FVector3d(500.f, 500.f, 500.f));
	SetCurrentRotation(FVector3d(0.f, 0.f, 0.f));
	SetCurrentScale(FVector3d(1.f,1.f,1.f));
	
	// Create CameraComponent and attach it to the root
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetRelativeRotation(FRotator(-90.0f, 0.0f, -90.0f));
	CameraComponent->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	UEventManager::Subscribe(EEventTypes::OnCursorMoveRatio, *this);
}

// Called when the game starts or when spawned
void AClientCamera::BeginPlay()
{
	Super::BeginPlay();
}

void AClientCamera::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UEventManager::ClearSubscribers();
	Super::EndPlay(EndPlayReason);
}

void AClientCamera::HandleEvent(EEventTypes EventType, DataPacket EventData)
{
	SetTweenProgress(0.f);
	TweenDuration = 0.05f;
	const float MoveDistance = 240.f;
	const float XSpeed = (EventData.Float1*EventData.Float1)*((EventData.Float1>0.f)?1.f:-1.f);
	const float YSpeed = (EventData.Float2*EventData.Float2)*((EventData.Float2>0.f)?1.f:-1.f);
	SetTargetLocation(FVector3d(CurrentLocation.X+XSpeed*MoveDistance, CurrentLocation.Y+YSpeed*MoveDistance, CurrentLocation.Z));
}

void AClientCamera::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	ProgressTween(DeltaSeconds);
	UpdateTween();
	if (CurrentTweenProgress < 1.f)
	{
		SetActorLocation(CurrentLocation);
	}
}

FString AClientCamera::GetName() const
{
	return "ClientCamera";
}

