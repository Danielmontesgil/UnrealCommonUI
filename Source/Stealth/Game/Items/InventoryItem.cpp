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

	ItemQuantity = 0;
}

void UInventoryItem::Init(const FItemData& ItemData)
{
	Id = ItemData.Id;
	Name = ItemData.Name;
	Icon = ItemData.Icon;
	UseText = ItemData.UseText;

	MaxStack = ItemData.MaxStack;
	SellPrice = ItemData.SellPrice;
}
