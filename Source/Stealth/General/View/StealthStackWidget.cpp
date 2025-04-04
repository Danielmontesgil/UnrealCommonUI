// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "StealthStackWidget.h"

#include "CommonActivatableWidget.h"
#include "Widgets/CommonActivatableWidgetContainer.h"

UCommonActivatableWidget* UStealthStackWidget::PushWidget(const TSubclassOf<UCommonActivatableWidget> &WidgetToPush, const EWidgetStack WidgetStack) const
{
	switch (WidgetStack)
	{
	case EWidgetStack::OverlayStack:
		return OverlayStack->AddWidget<UCommonActivatableWidget>(WidgetToPush);
	case EWidgetStack::MenuStack:
		return MenuStack->AddWidget<UCommonActivatableWidget>(WidgetToPush);
	case EWidgetStack::PopUpStack:
		return PopUpStack->AddWidget<UCommonActivatableWidget>(WidgetToPush);
	default:
		return HUDStack->AddWidget<UCommonActivatableWidget>(WidgetToPush);
	}
}
