// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

enum class EWidgetStack : uint8;
class UCommonActivatableWidgetStack;
class UCommonActivatableWidget;
class UStealthStackWidget;
/**
 * 
 */
UCLASS()
class STEALTH_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> StealthStackClass;

	UPROPERTY()
	UStealthStackWidget* StealthStackWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCommonActivatableWidget> MainMenuWidgetClass;

protected:
	virtual void BeginPlay() override;

	virtual void PushWidget(const TSubclassOf<UCommonActivatableWidget> &WidgetToPush, const EWidgetStack WidgetStack);
};
