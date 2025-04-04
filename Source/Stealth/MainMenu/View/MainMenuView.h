// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CommonWidgets/StealthCommonButton.h"
#include "MainMenuView.generated.h"

class AMainHUD;
class UStealthCommonButton;
/**
 * 
 */
UCLASS()
class STEALTH_API UMainMenuView : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	virtual UWidget* NativeGetDesiredFocusTarget() const override { return PlayButton; };

	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;

protected:
	virtual void NativeOnActivated() override;

private:
	UFUNCTION()
	void OnPlayButtonClicked();

	UFUNCTION()
	void OnExitButtonClicked();

public:
	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UStealthCommonButton* PlayButton;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UStealthCommonButton* SettingsButton;

	UPROPERTY(EditAnywhere, Category = "UI", meta = (BindWidget))
	UStealthCommonButton* ExitButton;

	UPROPERTY()
	AMainHUD* HUD;
	
	UPROPERTY(EditAnywhere, Category = UI)
	TSubclassOf<UCommonActivatableWidget> PlayButtonPopup;
};
