// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "InventorySlotViewModel.h"
#include "CommonHardwareVisibilityBorder.h"

void UInventorySlotViewModel::SetInventoryItem(UTexture2D* NewIcon, const int& NewItemAmount)
{
	UE_MVVM_SET_PROPERTY_VALUE(ItemIcon, NewIcon);
	UE_MVVM_SET_PROPERTY_VALUE(ItemAmount, NewItemAmount);
	UE_MVVM_SET_PROPERTY_VALUE(IsSlotFocusable, NewItemAmount > 0);
	ESlateVisibility NewAmountTextVisibility = NewItemAmount > 1 ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Hidden;
	UE_MVVM_SET_PROPERTY_VALUE(AmountTextVisibility, NewAmountTextVisibility);
	ESlateVisibility NewSlotVisibility = NewItemAmount > 0 ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Hidden;
	UE_MVVM_SET_PROPERTY_VALUE(SlotVisibility, NewSlotVisibility);
}
