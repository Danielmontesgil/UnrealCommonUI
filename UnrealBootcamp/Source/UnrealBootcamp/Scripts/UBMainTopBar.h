// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UBUserWidget.h"
#include "UBMainTopBar.generated.h"

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
	UUBSimpleText* TimerLabelText;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget))
	UUBSimpleText* TimerText;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UUBSimpleText* KillsLabelText;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget))
	UUBSimpleText* KillsText;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UUBSimpleText* EnemyKillsLabelText;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget))
	UUBSimpleText* EnemyKillsText;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UUBSimpleText* PointsLabelText;

	UPROPERTY(blueprintReadWrite, Category = "UI", meta = (BindWidget))
	UUBSimpleText* PointsText;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	UUBSimpleText* EnemyPointsLabelText;

	UPROPERTY(BlueprintReadWrite, Category = "UI", meta = (BindWidget))
	UUBSimpleText* EnemyPointsText;
};
