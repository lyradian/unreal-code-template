// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CodeTemplate/Constants/EventTypes.h"
#include "UObject/Object.h"
#include "LogManager.generated.h"

/**
 * 
 */
UCLASS()
class CODETEMPLATE_API ULogManager : public UObject
{
	GENERATED_BODY()
public:
	ULogManager();
	static TSet<FString> MessageHistory;
	static FString EnumToString(EEventTypes EnumValue);
	static FString GetTimeString();
	static void Log(FString Message);
	static void Log(FString Message, float Float);
	static void Log(FString Message, float Float, float Float2);
	static void Log(FString Message, FString String);
	static void Log(FString Message, FString String, FString String2);
	static void Log(FString Message, EEventTypes EventType);
	static void Log(FString Message, EEventTypes EventType, FString String);
	static void Log(FString Message, EEventTypes EventType, FString String, FString String2);
	static void Log(FString Message, int32 Integer);
	static void Log(FString Message, int32 Integer, int32 Integer2);
	
};
