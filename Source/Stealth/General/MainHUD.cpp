// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#include "MainHUD.h"
#include "CommonActivatableWidget.h"
#include "Blueprint/UserWidget.h"
#include "View/StealthStackWidget.h"

void AMainHUD::BeginPlay()
{
	if(!StealthStackClass)
	{
		return;
	}
	
	StealthStackWidget = Cast<UStealthStackWidget>(CreateWidget(GetOwningPlayerController(), StealthStackClass));
	if(StealthStackWidget)
	{
		StealthStackWidget->AddToViewport();
	}
}

UCommonActivatableWidget* AMainHUD::PushWidget(const TSubclassOf<UCommonActivatableWidget> &WidgetToPush, const EWidgetStack WidgetStack)
{
	return StealthStackWidget->PushWidget(WidgetToPush, WidgetStack);
}