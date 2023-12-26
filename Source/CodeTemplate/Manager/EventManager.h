// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "../Interfaces/Subscriber.h"
#include "CodeTemplate/Constants/EventTypes.h"
#include "EventManager.generated.h"


UCLASS()
class CODETEMPLATE_API UEventManager : public UObject
{
	GENERATED_BODY()

public:
	UEventManager();
	virtual ~UEventManager() override;
	static void Subscribe( EEventTypes EventType, ISubscriber &Subscriber);
	static void FireEvent(EEventTypes EventType, DataPacket EventData);
	static void AddEvent(EEventTypes EventType);
	static void ClearSubscribers();
	
private:
	static TMap<EEventTypes, TSet<ISubscriber*>> EventSubscribers;
};
