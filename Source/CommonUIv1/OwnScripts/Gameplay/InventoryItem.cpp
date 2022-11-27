// Fill out your copyright notice in the Description page of Project Settings.


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
