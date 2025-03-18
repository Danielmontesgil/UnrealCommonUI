// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

enum class EWidgetStack : uint8;
class UCommonActivatableWidget;
class UStealthStackWidget;
/**
 * 
 */
UCLASS()
class STEALTH_API AMainHUD : public AHUD
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> StealthStackClass;

	UPROPERTY()
	UStealthStackWidget* StealthStackWidget;

protected:
	virtual void BeginPlay() override;

public:
	virtual void PushWidget(const TSubclassOf<UCommonActivatableWidget> &WidgetToPush, const EWidgetStack WidgetStack);
};
