// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "Components/UniformGridSlot.h"
#include "Components/UniformGridPanel.h"

// This just to test how to add widgets using Synchronize Properties

// void UGameHUD::SynchronizeProperties()
// {
// 	Super::SynchronizeProperties();
//
// 	for (int32 y = 0; y < Rows; ++y)
// 	{
// 		for (int32 x = 0; x < Columns; ++x)
// 		{
// 			UUserWidget* Widget = CreateWidget<UUserWidget>(
// 				GetWorld(), InventorySlotClass);
// 			if (Widget)
// 			{
// 				UUniformGridSlot* GridSlot = Grid->AddChildToUniformGrid(
// 					Widget);
// 				GridSlot->SetColumn(x);
// 				GridSlot->SetRow(y);
// 				InventorySlots.Add(Widget);
// 			}
// 		}
// 	}
// }
