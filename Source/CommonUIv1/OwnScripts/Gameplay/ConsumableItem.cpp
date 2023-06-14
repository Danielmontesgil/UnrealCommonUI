// Copyright 2023 Daniel Montes Gil.

// Specific inventory item that can be used from the Inventory


#include "ConsumableItem.h"

#include "ItemDataBase.h"

void UConsumableItem::Init(FItemData* Item)
{
	if(Item)
	{
		Name = Item->Name;
		Icon = Item->Icon;
		SellPrice = Item->SellPrice;
		MaxStack = Item->MaxStack;
		UseText = Item->UseText;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Item from ItemDataBase, using Inspector Values"));
	}
}

FString UConsumableItem::GetInfoDisplayText()
{
	FString Text = FString::Printf(TEXT("%s\nUse: %s\nMaxStack: %u\nSellPrice: %u Gold\n0"),*Name,*UseText,MaxStack,SellPrice);
	return Text;
}
