// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "InventorySlotModel.h"

#include "Stealth/Game/Items/InventoryItem.h"
#include "Stealth/Game/ViewModel/InventorySlotViewModel.h"

UInventorySlotModel::UInventorySlotModel()
{
}

void UInventorySlotModel::Init(UInventoryItem* ItemInSlot)
{
	InventoryItem = ItemInSlot;
}

void UInventorySlotModel::SetSlotViewModel(UMVVMViewModelBase* ViewModel)
{
	if(ViewModel)
	{
		if(UInventorySlotViewModel* InventorySlotViewModel = Cast<UInventorySlotViewModel>(ViewModel))
		{
			SlotViewModel = InventorySlotViewModel;
			UpdateView();
		}
	}
}

void UInventorySlotModel::UpdateView()
{
	if (SlotViewModel)
	{
		if(InventoryItem)
		{
			SlotViewModel->SetInventoryItem(InventoryItem->GetIcon(), InventoryItem->GetItemQuantity());
			return;
		}

		SlotViewModel->SetInventoryItem(nullptr, 0);
	}
}

UInventoryItem* UInventorySlotModel::GetInventoryItem()
{
	return InventoryItem;
}
