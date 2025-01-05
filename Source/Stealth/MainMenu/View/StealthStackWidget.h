// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "StealthStackWidget.generated.h"


class UCommonActivatableWidget;
class UCommonActivatableWidgetStack;

UENUM()
enum class EWidgetStack : uint8
{
	MenuStack = 0,
	PopUpStack = 1
};

/**
 * 
 */
UCLASS()
class STEALTH_API UStealthStackWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta=(BindWidget))
	UCommonActivatableWidgetStack* MenuStack;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UCommonActivatableWidgetStack* PopUpStack;

	void PushWidget(const TSubclassOf<UCommonActivatableWidget> &WidgetToPush, const EWidgetStack WidgetStack) const;
};
