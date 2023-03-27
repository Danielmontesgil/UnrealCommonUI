// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "InventorySlot.h"
#include "CommonUIv1/OwnScripts/Gameplay/InventoryComponent.h"
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


void UGameHUD::OnDrawInventorySlot(uint32 Index, uint32 Quantity, UTexture2D* ItemIcon) const
{
	if(InventoryContainer->GetVisibility() == ESlateVisibility::Hidden)
	{
		return;
	}
	if(const UInventorySlot* SlotWidget = Cast<UInventorySlot>(InventorySlots[Index]))
	{
		if(ItemIcon)
		{
			SlotWidget->FillSlotInfo(Quantity,ItemIcon);
		}
	}
}
