// Copyright Epic Games, Inc. All Rights Reserved.

#include "CommonUIv1GameMode.h"
#include "CommonUIv1PlayerController.h"
#include "CommonUIv1Character.h"
#include "UObject/ConstructorHelpers.h"

ACommonUIv1GameMode::ACommonUIv1GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ACommonUIv1PlayerController::StaticClass();

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