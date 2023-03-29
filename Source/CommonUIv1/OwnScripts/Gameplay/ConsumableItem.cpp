// Copyright 2023 Daniel Montes Gil.

// Specific inventory item that can be used from the Inventory


#include "ConsumableItem.h"

FString UConsumableItem::GetInfoDisplayText()
{
	FString Text = FString::Printf(TEXT("%s\nUse: %s\nMaxStack: %u\nSellPrice: %u Gold\n0"),*Name,*UseText,MaxStack,SellPrice);
	return Text;
}
