// Fill out your copyright notice in the Description page of Project Settings.


#include "MotionTweener.h"


void IMotionTweener::SetCurrentLocation(FVector3d NewLocation)
{
	CurrentLocation = NewLocation;
	EndLocation = NewLocation;
	StartLocation = NewLocation;
}

void IMotionTweener::SetCurrentRotation(FVector3d NewRotation)
{
	CurrentRotation = NewRotation;
	EndRotation = NewRotation;
	StartRotation = NewRotation;
}

void IMotionTweener::SetCurrentScale(FVector3d NewScale)
{
	CurrentScale = NewScale;
	EndScale = NewScale;
	StartScale = NewScale;
}

void IMotionTweener::SetTargetLocation( FVector3d TargetLocation)
{
	StartLocation = CurrentLocation;
	EndLocation = TargetLocation;
}

void IMotionTweener::SetTargetRotation( FVector3d TargetRotation)
{
	StartRotation = CurrentRotation;
	EndRotation = TargetRotation;
}

void IMotionTweener::SetTargetScale( FVector3d TargetScale)
{
	StartScale = CurrentScale;
	EndScale = TargetScale;
}

void IMotionTweener::SetTweenProgress(float NewProgress)
{
	CurrentTweenProgress = NewProgress;
	CurrentTweenProgress = FMath::Clamp(CurrentTweenProgress, 0.f, 1.f);
}

void IMotionTweener::ProgressTween(float DeltaTime)
{
	SetTweenProgress( CurrentTweenProgress + DeltaTime);
}

void IMotionTweener::UpdateTween()
{
	CurrentLocation = FMath::Lerp(StartLocation, EndLocation, CurrentTweenProgress);
	CurrentRotation = FMath::Lerp(StartRotation, EndRotation, CurrentTweenProgress);
	CurrentScale = FMath::Lerp(StartScale, EndScale, CurrentTweenProgress);
}

