// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "PlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class STEALTH_API UPlayerHUD : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;
};
