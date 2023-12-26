// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CodeTemplate/Constants/EventTypes.h"
#include "CodeTemplate/Models/DataPacket.h"
#include "UObject/Interface.h"
#include "Subscriber.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USubscriber : public UInterface
{
	GENERATED_BODY()
};
class CODETEMPLATE_API ISubscriber
{
	GENERATED_BODY()
public:
	virtual void HandleEvent(EEventTypes EventType, DataPacket EventData) = 0;
	virtual FString GetName() const { return FString(TEXT("Unnamed")); }
	
};
