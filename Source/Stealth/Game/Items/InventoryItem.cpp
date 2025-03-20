// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "InventoryItem.h"
#include "Stealth/Data/DataStructs.h"

UInventoryItem::UInventoryItem()
{
	Name = "";
	Icon = nullptr;
	UseText = "";

	MaxStack = 0;
	SellPrice = 0;
}

UInventoryItem::UInventoryItem(FItemData ItemData)
{
	Name = ItemData.Name;
	Icon = ItemData.Icon;
	UseText = ItemData.UseText;

	MaxStack = ItemData.MaxStack;
	SellPrice = ItemData.SellPrice;
}
