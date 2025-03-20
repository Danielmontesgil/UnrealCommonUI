// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "InventoryModel.h"

#include "Stealth/Game/Items/InventoryItem.h"

void UInventoryModel::AddItem(const UInventoryItem* ItemToAdd, const uint32 ItemAmount)
{
}

bool UInventoryModel::RemoveItem(const UInventoryItem* ItemToRemove, const uint32 ItemAmount)
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
