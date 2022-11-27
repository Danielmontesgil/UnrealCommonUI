// Fill out your copyright notice in the Description page of Project Settings.


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
