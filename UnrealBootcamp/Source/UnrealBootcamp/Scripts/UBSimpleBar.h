// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UBUserWidget.h"
#include "UBSimpleBar.generated.h"

class UProgressBar;
/**
 * 
 */
UCLASS()
class UNREALBOOTCAMP_API UUBSimpleBar : public UUBUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
		TObjectPtr<UProgressBar> ProgressBar;
};
