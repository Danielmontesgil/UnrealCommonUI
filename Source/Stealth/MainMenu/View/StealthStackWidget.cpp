// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "StealthStackWidget.h"

#include "CommonActivatableWidget.h"
#include "Widgets/CommonActivatableWidgetContainer.h"

void UStealthStackWidget::PushWidget(const TSubclassOf<UCommonActivatableWidget> &WidgetToPush, const EWidgetStack WidgetStack) const
{
	switch (WidgetStack)
	{
	case EWidgetStack::MenuStack:
		MenuStack->AddWidget<UCommonActivatableWidget>(WidgetToPush);
		break;
	case EWidgetStack::PopUpStack:
		PopUpStack->AddWidget<UCommonActivatableWidget>(WidgetToPush);
		break;
	}
}
