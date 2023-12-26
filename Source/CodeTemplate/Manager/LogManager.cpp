// Fill out your copyright notice in the Description page of Project Settings.


#include "LogManager.h"
#include "EventManager.h"
#include "chrono"
#include "iomanip"

TSet<FString> ULogManager::MessageHistory;

ULogManager::ULogManager()
{
}

FString ULogManager::GetTimeString()
{
	auto CurrentTimePoint = std::chrono::system_clock::now();
	auto CurrentTime = std::chrono::system_clock::to_time_t(CurrentTimePoint);
	struct tm TimeInfo;
	localtime_s(&TimeInfo, &CurrentTime);
	std::ostringstream FormattedTime;
	FormattedTime << std::put_time(&TimeInfo, "%H:%M");
	return FString(FormattedTime.str().c_str());
}

void ULogManager::Log(FString Message)
{
	FString TimeString = GetTimeString();
	FString FormattedString = FString::Printf(TEXT("[Logger %s] %s"), *TimeString, *Message);
	if (!MessageHistory.Contains(FormattedString))
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *FormattedString);
		MessageHistory.Add(FormattedString);
	}
}

FString ULogManager::EnumToString(EEventTypes EnumValue)
{
	UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EEventTypes"), true);
	if (!EnumPtr)
	{
		return FString(TEXT("InvalidEnum"));
	}
	FText EnumName = EnumPtr->GetDisplayNameTextByIndex(static_cast<uint8>(EnumValue));
	return FString(EnumName.ToString());
}

void ULogManager::Log(FString Message, FString String, FString String2)
{
	FString FormattedString = FString::Printf(TEXT("%s (%s, %s)"), *Message, *String, *String2);
    Log(FormattedString);
}

void ULogManager::Log(FString Message, EEventTypes EventType)
{
	Log(Message, *EnumToString(EventType));
}

void ULogManager::Log(FString Message, EEventTypes EventType, FString String)
{
	FString FormattedString = FString::Printf(TEXT("%s (%s, %s)"), *Message, *EnumToString(EventType), *String);
	Log(FormattedString);
}

void ULogManager::Log(FString Message, int32 Integer)
{
	FString FormattedString = FString::Printf(TEXT("%s (%d)"), *Message, Integer);
	Log(FormattedString);
}

void ULogManager::Log(FString Message, int32 Integer, int32 Integer2)
{
	FString FormattedString = FString::Printf(TEXT("%s (%d, %d)"), *Message, Integer, Integer2);
	Log(FormattedString);
}

void ULogManager::Log(FString Message, EEventTypes EventType, FString String, FString String2)
{
	FString FormattedString = FString::Printf(TEXT("%s (%s, %s, %s)"), *Message, *EnumToString(EventType), *String, *String2);
	Log(FormattedString);
}

void ULogManager::Log(FString Message, float Float)
{
	FString FormattedString = FString::Printf(TEXT("%s (%f))"), *Message,Float);
	Log(FormattedString);
}

void ULogManager::Log(FString Message, float Float, float Float2)
{
	FString FormattedString = FString::Printf(TEXT("%s (%f, %f))"), *Message,Float, Float2);
	Log(FormattedString);
}

void ULogManager::Log(FString Message, FString String)
{
	FString FormattedString = FString::Printf(TEXT("%s (%s)"), *Message, *String);
	Log(FormattedString);
}
