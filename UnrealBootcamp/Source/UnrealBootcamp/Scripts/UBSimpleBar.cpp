// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "UBSimpleBar.h"

#include "Components/ProgressBar.h"

void UUBSimpleBar::NativePreConstruct()
{
	ProgressBar->SetPercent(Percentage);
}
