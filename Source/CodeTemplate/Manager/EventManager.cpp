
#include "EventManager.h"

#include <functional>

#include "LogManager.h"
#include "CodeTemplate/Constants/EventTypes.h"
#include "CodeTemplate/Models/DataPacket.h"

TMap<EEventTypes, TSet<ISubscriber*>> UEventManager::EventSubscribers;

UEventManager::UEventManager()
{
	//EventSubscribers = TMap<EEventTypes, TSet<ISubscriber*>>();
	
	for (uint8 i = 0; i < static_cast<uint8>(EEventTypes::Last); i++)
	{
		const EEventTypes EventType = static_cast<EEventTypes>(i);
		AddEvent(EventType);
	}
}

UEventManager::~UEventManager()
{
	ClearSubscribers();
}

void UEventManager::AddEvent(EEventTypes EventType)
{
	if (!EventSubscribers.Contains(EventType))
	{
		ULogManager::Log("Adding Event: ", EventType);
		EventSubscribers.Add( EventType, *(new TSet<ISubscriber*>()));
	}
}

void UEventManager::FireEvent(EEventTypes EventType, DataPacket EventData)
{
	TSet<ISubscriber*> Subscribers = EventSubscribers.FindOrAdd(EventType);
	for (ISubscriber* Subscriber : Subscribers)
	{
		ULogManager::Log("Subscriber found for Event: ", EventType, Subscriber->GetName());
		Subscriber->HandleEvent(EventType, EventData);
	}
}

void UEventManager::Subscribe(EEventTypes EventType, ISubscriber &Subscriber)
{
	TSet<ISubscriber*> Subscribers = EventSubscribers.FindOrAdd(EventType);
	if (!Subscribers.Contains(&Subscriber))
	{
		ULogManager::Log("Adding Subscriber to Event: ", EventType, Subscriber.GetName());
		Subscribers.Add(&Subscriber);
		EventSubscribers.Remove(EventType);
		EventSubscribers.Add(EventType, Subscribers);
		ULogManager::Log("Subscribers count after adding: ", Subscribers.Num());
	}
}

void UEventManager::ClearSubscribers()
{
	EventSubscribers.Empty();
	for (auto& Pair : EventSubscribers)
	{
		TSet<ISubscriber*>& Subscribers = Pair.Value;
		Subscribers.Empty();
	}
}
