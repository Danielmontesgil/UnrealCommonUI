// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GenericPopUpView.generated.h"

class UCommonTextBlock;
class UStealthCommonButton;
/**
 * 
 */
UCLASS()
class STEALTH_API UGenericPopUpView : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	UStealthCommonButton* OkButton;

	UPROPERTY(meta = (BindWidget))
	UStealthCommonButton* CancelButton;

	UPROPERTY(meta = (BindWidget))
	UCommonTextBlock* PopUpText;

	virtual void NativeOnActivated() override;
};
