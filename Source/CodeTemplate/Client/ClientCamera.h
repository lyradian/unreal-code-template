// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "CodeTemplate/Interfaces/MotionTweener.h"
#include "CodeTemplate/Interfaces/Subscriber.h"
#include "ClientCamera.generated.h"

UCLASS()
class CODETEMPLATE_API AClientCamera : public APawn, public ISubscriber, public IMotionTweener
{
	GENERATED_BODY()
	
public:
	AClientCamera();
	virtual void HandleEvent(EEventTypes EventType, DataPacket EventData) override;
	virtual void Tick(float DeltaSeconds) override;
	virtual FString GetName() const override;
	
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
private:
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;
};
