// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemSlot.h"

UItemSlot::UItemSlot()
{
	
}

UItemSlot::UItemSlot(UInventoryItem* Item, uint32 Quantity)
{
	this->Item = Item;
	this->Quantity = Quantity;
}
