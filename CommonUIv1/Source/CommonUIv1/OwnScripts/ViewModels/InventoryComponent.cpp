﻿// Copyright 2023 Daniel Montes Gil.

// This class is the ViewModel for the inventory system, it handles the events that come from the Player and the View
// it also communicates with the Model to updated the info properly

#include "InventoryComponent.h"
#include "Components/ActorComponent.h"
#include "CommonUIv1/CommonUIv1PlayerController.h"
#include "CommonUIv1/OwnScripts/Models/InventoryModel.h"
#include "CommonUIv1/OwnScripts/UI/InventorySlot.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UInventoryComponent::Init(uint32 Size)
{
	
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<ACommonUIv1PlayerController>(GetWorld()->GetFirstPlayerController());
	
	if(PlayerController)
	{
		PlayerController->OnInventoryPressedDelegate.AddUObject(this, &UInventoryComponent::OnInventoryOpened);
		PlayerController->OnItemAddedDelegate.BindUObject(this,&UInventoryComponent::AddItem);
	}

	InventoryModel = NewObject<UInventoryModel>();
	InventoryModel->Init(5);
}

void UInventoryComponent::AddItem(UItemSlot* Slot) const
{
	if(InventoryModel->AddItem(Slot))
	{
		UpdateUI();
	}
}

void UInventoryComponent::RemoveAt(size_t SlotIndex) const
{
	if(InventoryModel->RemoveAt(SlotIndex))
	{
		UpdateUI();
	}
}

void UInventoryComponent::RemoveItem(UItemSlot* Slot) const
{
	if(InventoryModel->RemoveItem(Slot))
	{
		UpdateUI();
	}

}

void UInventoryComponent::Swap(uint32 IndexOne, uint32 IndexTwo) const
{
	if(InventoryModel->Swap(IndexOne,IndexTwo))
	{
		UpdateUI();
	}
}

void UInventoryComponent::UpdateUI() const
{
	OnDrawInventorySlotDelegate.Broadcast(InventoryModel->GetInventory());
}

void UInventoryComponent::OnInventoryOpened() const
{
	OnShowInventoryDelegate.Broadcast();
	UpdateUI();
}
