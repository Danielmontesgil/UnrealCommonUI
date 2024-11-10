// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "UBSimpleText.h"
#include "Components/TextBlock.h"

void UUBSimpleText::SynchronizeProperties()
{
	TextBlock->SetText(Text);
	// TextBlock->SetFont(Font);
}
