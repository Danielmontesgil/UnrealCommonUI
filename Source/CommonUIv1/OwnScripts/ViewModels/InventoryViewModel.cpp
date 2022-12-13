// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryViewModel.h"
#include "CommonUIv1/CommonUIv1Character.h"
#include "CommonUIv1/CommonUIv1PlayerController.h"
#include "CommonUIv1/OwnScripts/Gameplay/InventoryComponent.h"
#include "CommonUIv1/OwnScripts/Gameplay/ItemSlot.h"

void UInventoryViewModel::Init(ACommonUIv1PlayerController* Controller)
{
	if(!Controller)
	{
		return;
	}
	PlayerController = Controller;
	if(const auto Character = Cast<ACommonUIv1Character>(PlayerController->GetCharacter()))
	{
		Inventory = Character->GetInventoryComponent();
	}
	
	RegisterDelegates();
}

void UInventoryViewModel::RegisterDelegates()
{	
	if(PlayerController && Inventory)
	{
		PlayerController->OnInventoryOpenedDelegate.AddUObject(this,&UInventoryViewModel::OnInventoryOpened);
		Inventory->OnInventoryUpdatedDelegate.AddUObject(this,&UInventoryViewModel::UpdateUI);
	}
}

void UInventoryViewModel::UpdateUI()
{
	if(const ACommonUIv1Character* Character = Cast<ACommonUIv1Character>(PlayerController->GetCharacter()))
	{
		if(const UInventoryComponent* InventoryComponent = Character->GetInventoryComponent())
		{
			for(uint32 i = 0; i < Character->GetInventorySize(); i++)
			{
				const UItemSlot* ItemSlot = InventoryComponent->GetSlotByIndex(i);
				if(ItemSlot && ItemSlot->Item)
				{
					OnDrawInventorySlotDelegate.Broadcast(i, ItemSlot->Quantity, ItemSlot->Item->GetIcon());
				}
			}
		}
	}
}

void UInventoryViewModel::OnInventoryOpened()
{
	OnInventoryOpenedDelegate.Broadcast();
	UpdateUI();
}
