// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#include "MainMenuHUD.h"
#include "CommonActivatableWidget.h"
#include "Blueprint/UserWidget.h"
#include "View/StealthStackWidget.h"


void AMainMenuHUD::BeginPlay()
{
	if(!StealthStackClass)
	{
		return;
	}

	APlayerController* PlayerController = GetOwningPlayerController();
	if(PlayerController)
	{
		PlayerController->SetInputMode(FInputModeUIOnly());
		PlayerController->SetShowMouseCursor(true);
	}
	
	StealthStackWidget = Cast<UStealthStackWidget>(CreateWidget(GetOwningPlayerController(), StealthStackClass));
	if(StealthStackWidget)
	{
		StealthStackWidget->AddToViewport();

		if(MainMenuWidgetClass)
		{
			PushWidget(MainMenuWidgetClass, EWidgetStack::MenuStack);
		}
	}
}

void AMainMenuHUD::PushWidget(const TSubclassOf<UCommonActivatableWidget> &WidgetToPush, const EWidgetStack WidgetStack)
{
	StealthStackWidget->PushWidget(WidgetToPush, WidgetStack);
}
