
#pragma once


UENUM(BlueprintType)
enum class EEventTypes : uint8
{
	OnCursorMoveRatio UMETA(DisplayName = "OnCursorMoveRatio"),
	OnCursorMovePosition UMETA(DisplayName = "OnCursorMovePosition"),
	OnCursorSelect UMETA(DisplayName = "OnCursorSelect"),
	Last UMETA(DisplayName = "Last")
};




