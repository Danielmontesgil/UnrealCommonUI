// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "InventoryModel.h"
#include "InventorySlotModel.h"
#include "Stealth/Game/Items/InventoryItem.h"
#include "InventorySlotModel.h"
#include "MVVMViewModelBase.h"

UInventoryModel::UInventoryModel()
{
	Items.SetNum(20);

	for (int32 i = 0; i < Items.Num(); i++)
	{
		Items[i] = NewObject<UInventorySlotModel>();
	}
}

void UInventoryModel::AddItem(UInventoryItem* ItemToAdd)
{
	for(int i = 0; i < Items.Num(); i++)
	{
		if(UInventoryItem* ItemInSlot = Items[i]->GetInventoryItem(); ItemInSlot != nullptr)
		{
			if(ItemInSlot->GetId() == ItemToAdd->GetId())
			{
				const int32 RemainingSpace = ItemInSlot->GetMaxStack() - ItemInSlot->GetItemQuantity();
				if(ItemToAdd->GetItemQuantity() <= RemainingSpace)
				{
					ItemInSlot->ModifyItemQuantity(ItemToAdd->GetItemQuantity());
					Items[i]->UpdateView();
					return;
				}
			
				ItemToAdd->ModifyItemQuantity(-RemainingSpace);
				ItemInSlot->ModifyItemQuantity(RemainingSpace);

				Items[i]->UpdateView();
			}
		}
	}
	
	for(int i = 0; i < Items.Num(); i++)
	{
		if(UInventorySlotModel* SlotModel = Items[i]; SlotModel->GetInventoryItem() == nullptr)
		{
			if(ItemToAdd->GetItemQuantity() <= ItemToAdd->GetMaxStack())
			{
				Items[i]->Init(ItemToAdd);
				Items[i]->UpdateView();
				return;
			}

			SlotModel->Init(ItemToAdd);
			SlotModel->GetInventoryItem()->ModifyItemQuantity(ItemToAdd->GetMaxStack());
			ItemToAdd->ModifyItemQuantity(-ItemToAdd->GetMaxStack());

			SlotModel->UpdateView();
		}
	}
}

bool UInventoryModel::RemoveItem(const UInventoryItem* ItemToRemove)
{
	return true;
}

const UInventoryItem* UInventoryModel::GetItemByIndex(const uint32& ItemIndex) const
{
	return nullptr;
}

const uint32 UInventoryModel::GetItemQuantity(const UInventoryItem* Item)
{
	return 0;
}

bool UInventoryModel::HasItem(const UInventoryItem* Item)
{
	return true;
}

void UInventoryModel::SetSlotViewModel(UMVVMViewModelBase* ViewModel, const int SlotIndex)
{
	if(ViewModel)
	{
		if(UInventorySlotModel* Slot = Items[SlotIndex])
		{
			Slot->SetSlotViewModel(ViewModel);
		}
	}
}
