// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryViewModel.h"
#include "CommonUIv1/CommonUIv1Character.h"
#include "CommonUIv1/OwnScripts/Gameplay/InventoryComponent.h"
#include "CommonUIv1/OwnScripts/Gameplay/ItemSlot.h"

void UInventoryViewModel::Init(const ACommonUIv1Character* Character)
{
	if(Character->GetInventoryComponent())
	{
		Inventory = Character->GetInventoryComponent();
	}
	
	RegisterDelegates();
}

void UInventoryViewModel::RegisterDelegates()
{	
	if(Inventory)
	{
		Inventory->OnInventoryUpdatedDelegate.AddUObject(this, &UInventoryViewModel::OnInventoryUpdated);
	}
}

void UInventoryViewModel::UpdateUI()
{
	for(size_t i = 0; i < InventoryData.Num(); i++)
	{
		const UItemSlot* ItemSlot = InventoryData[i];
		if(ItemSlot && ItemSlot->Item)
		{
			OnDrawInventorySlotDelegate.Broadcast(i, ItemSlot->Quantity, ItemSlot->Item->GetIcon());
		}
	}
}

void UInventoryViewModel::OnInventoryUpdated(bool NeedToOpenInventory, const TArray<UItemSlot*>& ItemSlots)
{
	InventoryData = ItemSlots;
	if(NeedToOpenInventory)
	{
		OnShowInventoryDelegate.Broadcast();
	}
	UpdateUI();
}
