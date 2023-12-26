// Fill out your copyright notice in the Description page of Project Settings.


#include "GridFloor.h"
#include "CodeTemplate/Manager/EventManager.h"
#include "CodeTemplate/Manager/LogManager.h"
#include "Materials/MaterialInstanceDynamic.h"

AGridFloor::AGridFloor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	
}


void AGridFloor::HandleEvent(EEventTypes EventType, DataPacket EventData)
{
	if (GridFloorMaterialInstance)
	{
		GridFloorMaterialInstance->SetVectorParameterValue("CursorLocation", FLinearColor(EventData.Float1, EventData.Float2, 0, 0));
	}
}

FString AGridFloor::GetName() const
{
	return "GridFloor";
}

void AGridFloor::BeginPlay()
{
	UEventManager::Subscribe(EEventTypes::OnCursorMovePosition, *this);

	UStaticMeshComponent* MeshComponent = FindComponentByClass<UStaticMeshComponent>();
	if (MeshComponent)
		ULogManager::Log("MeshComponent Found");
	else
		ULogManager::Log("MeshComponent not Found");
	if (GridFloorMaterial)
		ULogManager::Log("Grid Floor Material found");
	else
		ULogManager::Log("Gridfloormaterial not Found");
	
	if (MeshComponent && GridFloorMaterial)
	{
		GridFloorMaterialInstance = UMaterialInstanceDynamic::Create(GridFloorMaterial, this);
		if (GridFloorMaterialInstance)
		{
			MeshComponent->SetMaterial(0, GridFloorMaterialInstance);
			ULogManager::Log("GridFloorMaterialInstance created successfully.");
			return;
		}
	}

	ULogManager::Log("Failed to create GridFloorMaterialInstance.");

	
	Super::BeginPlay();
}

void AGridFloor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UEventManager::ClearSubscribers();
	Super::EndPlay(EndPlayReason);
}

