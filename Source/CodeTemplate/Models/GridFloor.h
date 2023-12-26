// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataPacket.h"
#include "CodeTemplate/Constants/EventTypes.h"
#include "CodeTemplate/Interfaces/Subscriber.h"
#include "GameFramework/Actor.h"
#include "GridFloor.generated.h"

UCLASS()
class CODETEMPLATE_API AGridFloor : public AActor, public ISubscriber
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Floor")
	UMaterialInterface* GridFloorMaterial;

private:
	UMaterialInstanceDynamic* GridFloorMaterialInstance;

public:
	AGridFloor();
	void HandleEvent(EEventTypes EventType, DataPacket EventData);
	virtual FString GetName() const override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
