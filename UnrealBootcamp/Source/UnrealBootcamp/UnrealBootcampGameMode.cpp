// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealBootcampGameMode.h"
#include "UnrealBootcampCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealBootcampGameMode::AUnrealBootcampGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
