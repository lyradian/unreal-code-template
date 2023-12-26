// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MotionTweener.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UMotionTweener : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CODETEMPLATE_API IMotionTweener
{
	GENERATED_BODY()
	
public:
	FVector3d StartLocation;
	FVector3d StartRotation;
	FVector3d StartScale;
	FVector3d CurrentLocation;
	FVector3d CurrentRotation;
	FVector3d CurrentScale;
	FVector3d EndLocation;
	FVector3d EndRotation;
	FVector3d EndScale;
	float CurrentTweenProgress = 0;
	float TweenDuration = 1.f;
	
	virtual void SetCurrentLocation(FVector3d NewLocation);
	virtual void SetCurrentRotation(FVector3d NewRotation);
	virtual void SetCurrentScale(FVector3d NewScale);
	virtual void SetTargetLocation( FVector3d TargetLocation);
	virtual void SetTargetRotation( FVector3d TargetRotation);
	virtual void SetTargetScale( FVector3d TargetScale);
	virtual void SetTweenProgress(float NewProgress);
	virtual void ProgressTween(float DeltaTime);
	virtual void UpdateTween();
};
