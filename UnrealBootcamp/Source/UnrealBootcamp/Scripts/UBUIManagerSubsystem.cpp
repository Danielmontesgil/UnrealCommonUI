// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#include "UBUIManagerSubsystem.h"
#include "UBUserWidget.h"

void UUBUIManagerSubsystem::InstantiateWidget(const TSubclassOf<class UUBUserWidget> WidgetToCreateClass)
{	
	if(UUserWidget* Widget = CreateWidget<UUBUserWidget>(GetWorld(), WidgetToCreateClass))
	{
		Widget->AddToViewport();
	}
}
