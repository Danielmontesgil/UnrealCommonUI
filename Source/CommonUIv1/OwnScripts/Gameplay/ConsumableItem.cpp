// Fill out your copyright notice in the Description page of Project Settings.


#include "ConsumableItem.h"

FString UConsumableItem::GetInfoDisplayText()
{
	FString Text = FString::Printf(TEXT("%s\nUse: %s\nMaxStack: %u\nSellPrice: %u Gold\n0"),*Name,*UseText,MaxStack,SellPrice);
	return Text;
}
