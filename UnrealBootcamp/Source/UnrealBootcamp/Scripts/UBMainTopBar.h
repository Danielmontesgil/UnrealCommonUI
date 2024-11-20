// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UBUserWidget.h"
#include "UBMainTopBar.generated.h"

class UUBTextBlock;
class UUBSimpleText;
/**
 * 
 */
UCLASS()
class UNREALBOOTCAMP_API UUBMainTopBar : public UUBUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UUBTextBlock* TimerLabelText;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget))
	UUBTextBlock* TimerText;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UUBTextBlock* KillsLabelText;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget))
	UUBTextBlock* KillsText;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UUBTextBlock* EnemyKillsLabelText;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget))
	UUBTextBlock* EnemyKillsText;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UUBTextBlock* PointsLabelText;

	UPROPERTY(blueprintReadWrite, Category = "UI", meta = (BindWidget))
	UUBTextBlock* PointsText;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UUBTextBlock* EnemyPointsLabelText;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget))
	UUBTextBlock* EnemyPointsText;
};
