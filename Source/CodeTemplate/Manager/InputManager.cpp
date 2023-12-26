// Fill out your copyright notice in the Description page of Project Settings.

#include "InputManager.h"


#include "EventManager.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "LogManager.h"
#include "CodeTemplate/Constants/EventTypes.h"

void AInputManager::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("OnXAxis", this, &AInputManager::ReadCursorPosition);
	InputComponent->BindAxis("OnYAxis", this, &AInputManager::ReadCursorPosition);

}


void AInputManager::ReadCursorPosition(float AxisValue)
{
	GetMousePosition(ScreenX, ScreenY);
	DataPacket NewEventData;
	NewEventData.Float1 = ScreenX;
	NewEventData.Float2 = ScreenY;
	UEventManager::FireEvent(EEventTypes::OnCursorMovePosition, NewEventData);
	UpdateView();
}


void AInputManager::UpdateView()
{
	UGameViewportClient* ViewportClient = GEngine->GameViewport;
	if (ViewportClient)
	{
		FVector2D ViewportSize = FVector2D(ViewportClient->Viewport->GetSizeXY());
		const float ScreenRatioX = ScreenX/ViewportSize.X;
		const float ScreenRatioY = ScreenY/ViewportSize.Y;
		
		DataPacket NewEventData;
		NewEventData.Float1 = (ScreenRatioX<0.15f)?-(0.15f-ScreenRatioX)/0.15f:(ScreenRatioX > 0.85f)?(ScreenRatioX-0.85f)/0.15f:0.f;
		NewEventData.Float2 = (ScreenRatioY<0.15f)?-(0.15f-ScreenRatioY)/0.15f:(ScreenRatioY > 0.85f)?(ScreenRatioY-0.85f)/0.15f:0.f;
		if (NewEventData.Float1 || NewEventData.Float2)
		{
			UEventManager::FireEvent(EEventTypes::OnCursorMoveRatio, NewEventData);
		}
	}
}

void AInputManager::ReadTouchPosition(float AxisValue)
{
	GetInputTouchState(ETouchIndex::Touch1, ScreenX, ScreenY, IsSelecting);
}

void AInputManager::Report() const
{
	//ULogManager::Log(FString::Printf(TEXT("Input X: %f Input Y: %f"), ScreenX, ScreenY));
}
	