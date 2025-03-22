// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "InventorySlotViewModel.h"

void UInventorySlotViewModel::SetInventoryItem(UTexture2D* NewIcon, const int& NewItemAmount)
{
	UE_MVVM_SET_PROPERTY_VALUE(ItemIcon, NewIcon);
	UE_MVVM_SET_PROPERTY_VALUE(ItemAmount, NewItemAmount);
}
