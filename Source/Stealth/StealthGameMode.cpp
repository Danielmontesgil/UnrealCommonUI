// Copyright Epic Games, Inc. All Rights Reserved.

#include "StealthGameMode.h"
#include "General/MainHUD.h"
#include "MainMenu/View/StealthStackWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "CommonActivatableWidget.h"

AStealthGameMode::AStealthGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AStealthGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &AStealthGameMode::OnHudLoaded);
}

void AStealthGameMode::OnHudLoaded() const
{
	if(GameModeInitialWidgetClass)
	{
		if(AMainHUD* HUD = Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD()))
		{
			HUD->PushWidget(GameModeInitialWidgetClass, EWidgetStack::MenuStack);

			if(IsMenu)
			{
				if(APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
				{
					PlayerController->SetInputMode(FInputModeUIOnly());
					PlayerController->SetShowMouseCursor(true);
				}
			}
		}
	}
}

