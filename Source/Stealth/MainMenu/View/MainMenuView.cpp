// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "MainMenuView.h"

void UMainMenuView::NativeOnActivated()
{
	Super::NativeOnActivated();
	
	NativeGetDesiredFocusTarget()->SetFocus();
}
