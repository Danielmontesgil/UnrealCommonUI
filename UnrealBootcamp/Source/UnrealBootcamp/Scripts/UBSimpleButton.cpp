// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "UBSimpleButton.h"
#include "UBImage.h"
#include "UBTextBlock.h"

void UUBSimpleButton::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (Image)
	{
		Image->SetBrush(ButtonBrush);
	}

	if (TextBlock && !ButtonText.IsEmpty())
	{
		TextBlock->SetText(ButtonText);
	}
}

