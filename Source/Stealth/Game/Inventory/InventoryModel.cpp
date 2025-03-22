// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "InventoryModel.h"
#include "InventorySlotModel.h"
#include "Stealth/Game/Items/InventoryItem.h"
#include "InventorySlotModel.h"

UInventoryModel::UInventoryModel()
{
	Items.Init(NewObject<UInventorySlotModel>(),20);
}

void UInventoryModel::AddItem(UInventoryItem* ItemToAdd)
{
	for(int i = 0; Items.Num() - 1; i++)
	{
		if(Items[i]->GetInventoryItem() == nullptr)
		{
			Items[i]->Init(ItemToAdd);
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
