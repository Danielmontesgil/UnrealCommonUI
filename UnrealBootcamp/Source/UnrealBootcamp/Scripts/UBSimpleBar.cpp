// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "UBSimpleBar.h"

#include "Components/ProgressBar.h"

void UUBSimpleBar::SynchronizeProperties()
{
	if(ProgressBar)
	{
		ProgressBar->SetPercent(Percentage);
		ProgressBar->SetFillColorAndOpacity(GetColorAndOpacity());
	}
}
