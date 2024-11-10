// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UBUserWidget.h"
#include "UBSimpleText.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class UNREALBOOTCAMP_API UUBSimpleText : public UUBUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Text")
	FText Text;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Text")
	FSlateFontInfo Font;

	virtual void SynchronizeProperties() override;

protected:
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	TObjectPtr<UTextBlock> TextBlock;
};
