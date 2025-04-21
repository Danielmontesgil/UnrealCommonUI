// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "StealthActivatableWidget.generated.h"

/**
 * 
 */
UCLASS()
class STEALTH_API UStealthActivatableWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
};
