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

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
	UUBSimpleText* TimerLabelText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI", meta = (BindWidget))
	UUBSimpleText* TimerText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
	UUBSimpleText* KillsLabelText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI", meta = (BindWidget))
	UUBSimpleText* KillsText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
	UUBSimpleText* EnemyKillsLabelText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI", meta = (BindWidget))
	UUBSimpleText* EnemyKillsText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
	UUBSimpleText* PointsLabelText;

	UPROPERTY(blueprintReadWrite, EditAnywhere, Category = "UI", meta = (BindWidget))
	UUBSimpleText* PointsText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "UI")
	UUBSimpleText* EnemyPointsLabelText;

	UPROPERTY(BlueprintReadWrite, editAnywhere, Category = "UI", meta = (BindWidget))
	UUBSimpleText* EnemyPointsText;
};
