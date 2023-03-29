// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Components/ActorComponent.h"
#include "CommonUIv1/CommonUIv1PlayerController.h"
#include "CommonUIv1/OwnScripts/Models/InventoryModel.h"
#include "CommonUIv1/OwnScripts/Observer/Observer.h"
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
	InventoryModel = NewObject<UInventoryModel>();
	InventoryModel->Init(Size);
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
}

void UInventoryComponent::AddItem(UItemSlot* Slot)
{
	if(InventoryModel->AddItem(Slot))
	{
		UpdateUI();
	}
}

void UInventoryComponent::RemoveAt(size_t SlotIndex)
{
	if(InventoryModel->RemoveAt(SlotIndex))
	{
		UpdateUI();
	}
}

void UInventoryComponent::RemoveItem(UItemSlot* Slot)
{
	if(InventoryModel->RemoveItem(Slot))
	{
		UpdateUI();
	}

}

void UInventoryComponent::Swap(uint32 IndexOne, uint32 IndexTwo)
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

void UInventoryComponent::Attach(FString eventType, IObserver* Observer)
{
	if(ObserversMap.Contains(eventType))
	{
		ObserversMap[eventType].Push(Observer);
	}
	else
	{
		ObserversMap.Add(eventType,TArray{Observer});
	}
}

void UInventoryComponent::Detach(FString eventType, IObserver* Observer)
{
	if(ObserversMap.Contains(eventType))
	{
		for(int i = ObserversMap[eventType].Num() - 1; i >= 0; i--)
		{
			if(ObserversMap[eventType][i] == Observer)
			{
				ObserversMap[eventType].RemoveAt(i);
			}
		}
	}
}

void UInventoryComponent::Notify(FString eventType) const
{
	if(ObserversMap.Contains(eventType))
	{
		for(IObserver* mapObserver : ObserversMap[eventType])
		{
			mapObserver->Update();
		}
	}
}
