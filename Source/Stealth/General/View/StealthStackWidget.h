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
	HUDStack = 0,
	OverlayStack = 1,
	MenuStack = 2,
	PopUpStack = 3
};

/**
 * 
 */
UCLASS()
class STEALTH_API UStealthStackWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta=(BindWidget), BlueprintReadWrite)
	UCommonActivatableWidgetStack* HUDStack;

	UPROPERTY(EditAnywhere, meta=(BindWidget), BlueprintReadWrite)
	UCommonActivatableWidgetStack* OverlayStack;
	
	UPROPERTY(EditAnywhere, meta=(BindWidget), BlueprintReadWrite)
	UCommonActivatableWidgetStack* MenuStack;

	UPROPERTY(EditAnywhere, meta = (BindWidget), BlueprintReadWrite)
	UCommonActivatableWidgetStack* PopUpStack;

	UFUNCTION(BlueprintCallable)
	void PushWidget(const TSubclassOf<UCommonActivatableWidget> &WidgetToPush, const EWidgetStack WidgetStack) const;
};
