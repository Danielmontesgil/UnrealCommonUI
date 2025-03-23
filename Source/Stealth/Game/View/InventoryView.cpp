// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "InventoryView.h"
#include "Stealth/StealthCharacter.h"

void UInventoryView::NotifySlotViewModelCreation(UMVVMViewModelBase* ViewModel, const int Index)
{
	if(AStealthCharacter* Character = Cast<AStealthCharacter>(GetOwningPlayerPawn()))
	{
		Character->NotifySlotViewModel(ViewModel, Index);
	}
}
