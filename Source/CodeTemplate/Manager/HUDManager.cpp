// Fill out your copyright notice in the Description page of Project Settings.

#include "HUDManager.h"
#include "Engine/Canvas.h"
#include "EventManager.h"
#include "LogManager.h"

void AHUDManager::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	UEventManager::Subscribe(EEventTypes::OnCursorMovePosition, *this);
}

void AHUDManager::DrawHUD()
{
	Super::DrawHUD();
	if (GetCanvasPtr()!=nullptr)
	{
		DrawBox(FVector2D(205,205), FVector2D(100, 50));
		DrawText("Test",FVector2D(205,205));
	}
}


void AHUDManager::DrawBox(FVector2D Position, FVector2D Size) const
{
	const UCanvas* CanvasPtr = GetCanvasPtr();
	FLinearColor BoxColor;
	double TouchRadius = 15;
	if (IsOverlap(CursorPosition, FVector2D(TouchRadius,TouchRadius), Position, Size))
		BoxColor = FLinearColor(0.6f, 0.8f, 0.6f, 1.0f);
	else
		BoxColor = FLinearColor(0.3f, 0.2f, 0.4f, 0.8f);
		
	if (CanvasPtr != nullptr)
	{
		CanvasPtr->Canvas->DrawTile(Position.X-Size.X/2, Position.Y-Size.Y/2, Size.X, Size.Y, 0.0f, 0.0f, Size.X, Size.Y, BoxColor);
	}
}

void AHUDManager::DrawText(FString Message, FVector2D Position) const
{
	const UCanvas* CanvasPtr = GetCanvasPtr();
	constexpr FLinearColor TextColor(1.0f, 0.0f, 0.0f, 1.f);
	constexpr FLinearColor ShadowColor(1.0f, 0.0f, 0.0f, 1.f);
	UFont* DefaultFont = GEngine->GetLargeFont();
	DefaultFont->SetFontScalingFactor(2.0);
	if (CanvasPtr != nullptr && DefaultFont != nullptr)
	{
		CanvasPtr->Canvas->DrawShadowedText(Position.X, Position.Y, FText::FromString(Message), DefaultFont , TextColor, ShadowColor);
	}
}

//-------------------------------------------
// Assumes Centre-align
//-------------------------------------------
bool AHUDManager::IsOverlap(FVector2D SelectPosition, FVector2D SelectSize2D, FVector2D BoxPosition, FVector2D BoxSize2D ) const
{
	float BoxHalfWidth = BoxSize2D.X/2;
	float BoxHalfHeight = BoxSize2D.Y/2;
	float BufferWidth = SelectSize2D.X/2;
	float BufferHeight = SelectSize2D.Y/2;
	if (SelectPosition.X - BufferWidth >= BoxPosition.X - BoxHalfWidth
	&& SelectPosition.X + BufferWidth <= BoxPosition.X + BoxHalfWidth
	&& SelectPosition.Y - BufferHeight >= BoxPosition.Y - BoxHalfHeight
	&& SelectPosition.Y + BufferHeight <= BoxPosition.Y + BoxHalfHeight)
	{
		return true;
	}
	return false;
}

UCanvas* AHUDManager::GetCanvasPtr() const
{
	UCanvas* CanvasPtr = Canvas;
	if (CanvasPtr != nullptr)
	{
		return CanvasPtr;
	}
	return nullptr;
}

void AHUDManager::HandleEvent(EEventTypes EventType, DataPacket EventData)
{
	CursorPosition = FVector2D(EventData.Float1, EventData.Float2);
	//ULogManager::Log("Cursor Position Updated: ", (float)CursorPosition.X, (float)CursorPosition.Y);
}

FString AHUDManager::GetName() const
{
	return "HudManager";
}
