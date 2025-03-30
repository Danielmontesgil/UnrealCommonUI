// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "MainMenuView.h"
#include "../../General/View/StealthStackWidget.h"
#include "Kismet/GameplayStatics.h"
#include "../../General/MainHUD.h"

TOptional<FUIInputConfig> UMainMenuView::GetDesiredInputConfig() const
{
	return FUIInputConfig(ECommonInputMode::Menu, EMouseCaptureMode::NoCapture);
}

void UMainMenuView::NativeOnActivated()
{
	Super::NativeOnActivated();
	
	NativeGetDesiredFocusTarget()->SetFocus();

	PlayButton->OnClicked().AddUObject(this, &UMainMenuView::OnPlayButtonClicked);
	ExitButton->OnClicked().AddUObject(this, &UMainMenuView::OnExitButtonClicked);
}

void UMainMenuView::OnPlayButtonClicked()
{
	GetOwningPlayer()->SetInputMode(FInputModeGameOnly());
	GetWorld()->ServerTravel("ThirdPersonMap");
}

void UMainMenuView::OnExitButtonClicked()
{
	HUD = StaticCast<AMainHUD*>(GetOwningPlayer()->GetHUD());

	if(HUD)
	{
		HUD->PushWidget(PlayButtonPopup, EWidgetStack::PopUpStack);
	}
}