// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "MainMenuView.h"

#include "StealthStackWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Stealth/MainMenu/MainMenuHUD.h"

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
	UGameplayStatics::OpenLevel(this, "ThirdPersonMap");
}

void UMainMenuView::OnExitButtonClicked()
{
	HUD = StaticCast<AMainMenuHUD*>(GetOwningPlayer()->GetHUD());

	if(HUD)
	{
		HUD->PushWidget(PlayButtonPopup, EWidgetStack::PopUpStack);
	}
}