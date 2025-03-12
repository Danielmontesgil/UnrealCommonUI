// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "MainMenuView.h"

#include "StealthStackWidget.h"
#include "Stealth/MainMenu/MainMenuHUD.h"

void UMainMenuView::NativeOnActivated()
{
	Super::NativeOnActivated();
	
	NativeGetDesiredFocusTarget()->SetFocus();

	PlayButton->OnClicked().AddUObject(this, &UMainMenuView::OnPlayButtonClicked);
}

void UMainMenuView::OnPlayButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Button clicked!"));

	HUD = StaticCast<AMainMenuHUD*>(GetOwningPlayer()->GetHUD());

	if(HUD)
	{
		HUD->PushWidget(PlayButtonPopup, EWidgetStack::PopUpStack);
	}
}

