// Copyright 2023 Daniel Montes Gil.

// Items that can be part of the Inventory and have price and max stack

#include "InventoryItem.h"

uint32 UInventoryItem::GetSellPrice() const
{
	return SellPrice;
}

uint32 UInventoryItem::GetMaxStack() const
{
	return MaxStack;
}

bool UInventoryItem::operator==(const UInventoryItem& A)
{
	return Name == A.GetName();
}

bool UInventoryItem::operator!=(const UInventoryItem& A)
{
	return !(*this == A);
}
