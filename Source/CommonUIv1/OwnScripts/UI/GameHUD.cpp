// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "InventorySlot.h"
#include "CommonUIv1/CommonUIv1Character.h"
#include "CommonUIv1/OwnScripts/ViewModels/InventoryViewModel.h"
#include "Components/VerticalBox.h"

void UGameHUD::Init()
{
	InventoryViewModel = NewObject<UInventoryViewModel>();
	InventoryViewModel->Init(Cast<ACommonUIv1Character>(GetOwningPlayer()->GetCharacter()));
	InventoryViewModel->OnShowInventoryDelegate.AddUObject(this, &UGameHUD::OnShowInventory);
	InventoryViewModel->OnDrawInventorySlotDelegate.AddUObject(this,&UGameHUD::OnDrawInventorySlot);
	InventoryContainer->SetVisibility(ESlateVisibility::Hidden);
}

void UGameHUD::OnShowInventory() const
{
	InventoryContainer->SetVisibility(InventoryContainer->Visibility == ESlateVisibility::Hidden ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
}


void UGameHUD::OnDrawInventorySlot(uint32 Index, uint32 Quantity, UTexture2D* ItemIcon) const
{
	if(InventoryContainer->Visibility == ESlateVisibility::Hidden)
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
