// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "InventorySlot.h"
#include "CommonUIv1/OwnScripts/Gameplay/ItemSlot.h"
#include "CommonUIv1/OwnScripts/ViewModels/InventoryComponent.h"
#include "Components/VerticalBox.h"

void UGameHUD::Init(UInventoryComponent* Inventory)
{
	Inventory->OnShowInventoryDelegate.AddUObject(this, &UGameHUD::OnShowInventory);
	Inventory->OnDrawInventorySlotDelegate.AddUObject(this,&UGameHUD::OnDrawInventorySlot);
	InventoryContainer->SetVisibility(ESlateVisibility::Hidden);
}

void UGameHUD::OnShowInventory() const
{
	InventoryContainer->SetVisibility(InventoryContainer->GetVisibility() == ESlateVisibility::Hidden ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}


void UGameHUD::OnDrawInventorySlot(const TArray<UItemSlot*>& ItemSlots) const
{
	if(InventoryContainer->GetVisibility() == ESlateVisibility::Hidden)
	{
		return;
	}

	for(size_t i = 0; i < ItemSlots.Num(); i++)
	{
		const UItemSlot* ItemSlot = ItemSlots[i];
		if(ItemSlot && ItemSlot->Item)
		{
			if(const UInventorySlot* SlotWidget = Cast<UInventorySlot>(InventorySlots[i]))
			{
				if(ItemSlot->Item->GetIcon())
				{
					SlotWidget->FillSlotInfo(ItemSlot->Quantity,ItemSlot->Item->GetIcon());
				}
			}
		}
	}
}
