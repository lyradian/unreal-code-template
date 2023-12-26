// Copyright Epic Games, Inc. All Rights Reserved.

#include "CodeTemplateGameMode.h"
#include "CodeTemplatePlayerController.h"
#include "CodeTemplateCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACodeTemplateGameMode::ACodeTemplateGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ACodeTemplatePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}