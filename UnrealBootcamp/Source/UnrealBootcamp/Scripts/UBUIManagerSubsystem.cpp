// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#include "UBUIManagerSubsystem.h"
#include "Blueprint/UserWidget.h"

void UUBUIManagerSubsystem::InstantiateWidget(const TSubclassOf<class UUserWidget> MainMenuClass)
{	
	if(UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), MainMenuClass))
	{
		Widget->AddToViewport();
	}
}
