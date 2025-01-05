// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "StealthCommonButton.h"

#include "CommonTextBlock.h"

void UStealthCommonButton::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if(ButtonText)
	{
		ButtonText->SetText(Text);
	}
}

