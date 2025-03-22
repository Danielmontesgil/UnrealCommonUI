// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "InventoryModel.h"

#include "Stealth/Game/Items/InventoryItem.h"

UInventoryModel::UInventoryModel()
{
	Items.Reserve(20);
}

void UInventoryModel::AddItem(UInventoryItem* ItemToAdd)
{
	Items.Push(ItemToAdd);
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
