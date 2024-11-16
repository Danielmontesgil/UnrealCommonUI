// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UBUserWidget.h"
#include "UBMainUI.generated.h"

class UUBImage;
class UUBSimpleBar;
class UUBMainTopBar;
/**
 * 
 */
UCLASS()
class UNREALBOOTCAMP_API UUBMainUI : public UUBUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category="UI", meta = (BindWidget))
	UUBMainTopBar* TopBar;

	UPROPERTY(BlueprintReadWrite, Category="UI", meta = (BindWidget))
	UUBSimpleBar* HealthBar;

	UPROPERTY(BlueprintReadWrite, Category="UI", meta = (BindWidget))
	UUBSimpleBar* StaminaBar;

	UPROPERTY(BlueprintReadWrite, Category="UI", meta = (BindWidget))
	UUBImage* FlagIcon;
};
