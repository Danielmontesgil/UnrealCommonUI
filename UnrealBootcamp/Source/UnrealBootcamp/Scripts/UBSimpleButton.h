// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UBUserWidget.h"
#include "UBSimpleButton.generated.h"

/**
 * 
 */
UCLASS()
class UNREALBOOTCAMP_API UUBSimpleButton : public UUBUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Properties", meta = (ExposeOnSpawn = "true"))
	UTexture2D* ButtonImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button Properties", meta = (ExposeOnSpawn = "true"))
	FText ButtonText;

};
