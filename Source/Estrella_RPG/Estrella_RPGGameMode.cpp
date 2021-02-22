// Copyright Epic Games, Inc. All Rights Reserved.

#include "Estrella_RPGGameMode.h"
#include "Estrella_RPGPlayerController.h"
#include "Estrella_RPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEstrella_RPGGameMode::AEstrella_RPGGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AEstrella_RPGPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}