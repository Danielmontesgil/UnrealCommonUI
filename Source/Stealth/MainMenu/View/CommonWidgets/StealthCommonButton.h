// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "StealthCommonButton.generated.h"

class UCommonTextBlock;
/**
 * 
 */
UCLASS()
class STEALTH_API UStealthCommonButton : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	virtual void SynchronizeProperties() override;

private:
	UPROPERTY(meta=(BindWidget))
	UCommonTextBlock* ButtonText;

	UPROPERTY(EditAnywhere, Category="Button", meta=(AllowPrivateAccess="true"))
	FText Text;
};
