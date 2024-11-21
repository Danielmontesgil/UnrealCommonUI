// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UBUserWidget.h"
#include "UBSimpleButton.generated.h"

class UUBTextBlock;
class UUBImage;
/**
 * 
 */
UCLASS()
class UNREALBOOTCAMP_API UUBSimpleButton : public UUBUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Properties", meta = (ExposeOnSpawn = "true"))
	FSlateBrush ButtonBrush;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Properties", meta = (ExposeOnSpawn = "true"))
	FText ButtonText;

	virtual void SynchronizeProperties() override;

private:
	UPROPERTY(meta=(BindWidgetOptional))
	UUBImage* Image;

	UPROPERTY(meta=(BindWidget))
	UUBTextBlock* TextBlock;
};
