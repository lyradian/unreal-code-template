// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CodeTemplate/Interfaces/Subscriber.h"
#include "GameFramework/HUD.h"
#include "HUDManager.generated.h"

UCLASS()
class CODETEMPLATE_API AHUDManager : public AHUD, public ISubscriber
{
	GENERATED_BODY()
public:
	FVector2D CursorPosition;
	const FLinearColor BGColor = FLinearColor(0.3f, 0.2f, 0.4f, 0.8f);
	
protected:
	virtual void PostInitializeComponents() override;
public:
	virtual void DrawHUD() override;
	void DrawBox(FVector2D Position, FVector2D Size) const;
	void DrawText(FString Message, FVector2D Position) const;
	bool IsOverlap(FVector2D CursorPoint, FVector2D CursorRadius, FVector2D BoxPosition2D, FVector2D BoxSize2D) const;
	UCanvas* GetCanvasPtr() const;
	virtual void HandleEvent(EEventTypes EventType, DataPacket EventData) override;
	virtual FString GetName() const override;
};
