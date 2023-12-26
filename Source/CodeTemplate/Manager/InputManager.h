// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputManager.generated.h"

UCLASS()
class CODETEMPLATE_API AInputManager : public APlayerController
{
	GENERATED_BODY()

public:
	float ScreenX;
	float ScreenY;
	bool IsSelecting;
	void Report() const;
private:
	
protected:
	virtual void SetupInputComponent() override;
	
	void UpdateView();
	
	UFUNCTION()
	void ReadCursorPosition(float AxisValue);

	UFUNCTION()
	void ReadTouchPosition(float AxisValue);
};