// Copyright 2023 Daniel Montes Gil.

// This class is used on the Model to store all the items per Slot in the Inventory

#include "ItemSlot.h"
#include "InventoryItem.h"

UItemSlot::UItemSlot()
{
	
}

UItemSlot::UItemSlot(UInventoryItem* Item, uint32 Quantity)
{
	this->Item = Item;
	this->Quantity = Quantity;
}
