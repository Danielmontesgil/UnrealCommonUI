// Copyright 2023 Daniel Montes Gil.

//Part of the View that shows each Slot on the inventory with its icon and quantity

#include "InventorySlot.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UInventorySlot::FillSlotInfo(uint32 Quantity, UTexture2D* ItemImage) const
{
	ItemAmount->SetText(FText::AsNumber(Quantity));
	if(Quantity < 2)
	{
		ItemAmount->SetVisibility(ESlateVisibility::Hidden);
	}
	ItemIcon->SetBrushFromTexture(ItemImage);
}
