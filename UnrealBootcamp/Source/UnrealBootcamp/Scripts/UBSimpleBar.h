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
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Appearence", meta=(ClampMin="0", ClampMax="1", UIMin="0", UIMax="100"))
	float Percentage;

	virtual void SynchronizeProperties() override;
	
protected:
	
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	TObjectPtr<UProgressBar> ProgressBar;
};
