// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "ItemSlot.h"
#include "InventoryItem.h"
#include "CommonUIv1/CommonUIv1PlayerController.h"
#include "CommonUIv1/OwnScripts/UI/InventorySlot.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

UInventoryComponent::UInventoryComponent(size_t Size)
{
	ItemSlots.Init(NewObject<UItemSlot>() ,Size);
}

void UInventoryComponent::SetSize(size_t Size)
{
	ItemSlots.Init(NewObject<UItemSlot>() ,Size);
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = Cast<ACommonUIv1PlayerController>(GetWorld()->GetFirstPlayerController());
	
	if(PlayerController)
	{
		PlayerController->OnItemAddedDelegate.BindUObject(this,&UInventoryComponent::AddItem);
		PlayerController->OnInventoryOpenedDelegate.AddUObject(this,&UInventoryComponent::DrawInventory);
	}
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

UItemSlot* UInventoryComponent::GetSlotByIndex(const uint32 SlotIndex) const
{
	return ItemSlots[SlotIndex];
}

UItemSlot* UInventoryComponent::AddItem(UItemSlot* Slot)
{
	for (size_t i = 0; i < ItemSlots.Num(); i++)
	{
		if(ItemSlots[i]->Item != nullptr)
		{
			if(*ItemSlots[i]->Item == *Slot->Item)
			{
				const uint32 SlotRemainingSpace = ItemSlots[i]->Item->GetMaxStack() - ItemSlots[i]->Quantity;

				if(Slot->Quantity <= SlotRemainingSpace)
				{
					ItemSlots[i]->Quantity += Slot->Quantity;
					// Slot->Quantity = 0;
					// Event to update items
					if(UGameHUD* GameHUD = PlayerController->GetGameHUD())
					{
						DrawInventory(GameHUD);
					}
					return Slot;
				}
				
				if(SlotRemainingSpace > 0)
				{
					ItemSlots[i]->Quantity += SlotRemainingSpace;
					Slot->Quantity -= SlotRemainingSpace;
				}
			}
		}
	}

	for (size_t i = 0; i < ItemSlots.Num(); i++)
	{
		if(ItemSlots[i]->Item == nullptr)
		{
			if(Slot->Quantity <= Slot->Item->GetMaxStack())
			{
				ItemSlots[i] = Slot;
				// Slot->Quantity = 0;

				// Event to update items
				if(UGameHUD* GameHUD = PlayerController->GetGameHUD())
				{
					DrawInventory(GameHUD);
				}

				return Slot;
			}
			
			UItemSlot* ItemSlot = NewObject<UItemSlot>();
			ItemSlot->Item = Slot->Item;
			ItemSlot->Quantity = Slot->Item->GetMaxStack();
			
			ItemSlots[i] = ItemSlot;

			Slot->Quantity -= Slot->Item->GetMaxStack();
		}
	}

	// Event to update items
	if(UGameHUD* GameHUD = PlayerController->GetGameHUD())
	{
		DrawInventory(GameHUD);
	}

	return Slot;
}

uint32 UInventoryComponent::GetTotalQuantity(UInventoryItem* Item)
{
	uint32 TotalCount = 0;

	for(const UItemSlot* Slot : ItemSlots)
	{
		if(Slot->Item == nullptr)
		{
			continue;
		}

		if(Slot->Item != Item)
		{
			continue;
		}

		TotalCount += Slot->Quantity;
	}

	return TotalCount;
}

bool UInventoryComponent::HasItem(UInventoryItem* Item) const
{
	for(const UItemSlot* Slot : ItemSlots)
	{
		if(Slot->Item == nullptr)
		{
			continue;
		}

		if(Slot->Item != Item)
		{
			continue;
		}

		return true;
	}
	return false;
}

void UInventoryComponent::RemoveAt(size_t SlotIndex)
{
	if(SlotIndex < 0 || SlotIndex >= ItemSlots.Num() - 1)
	{
		return;
	}

	UItemSlot ItemSlot = UItemSlot();

	ItemSlots[SlotIndex] = &ItemSlot;
	
	// Event to update items
	if(UGameHUD* GameHUD = PlayerController->GetGameHUD())
	{
		DrawInventory(GameHUD);
	}
}

void UInventoryComponent::RemoveItem(UItemSlot* Slot)
{
	for(size_t i = 0; i < ItemSlots.Num(); i++)
	{
		if(ItemSlots[i]->Item != nullptr)
		{
			if(ItemSlots[i]->Item == Slot->Item)
			{
				if(ItemSlots[i]->Quantity < Slot->Quantity)
				{
					Slot->Quantity -= ItemSlots[i]->Quantity;
					UItemSlot NewItemSlot = UItemSlot();
					ItemSlots[i] = &NewItemSlot;
				}
				else
				{
					ItemSlots[i]->Quantity -= Slot->Quantity;

					if(ItemSlots[i]->Quantity == 0)
					{
						UItemSlot NewItemSlot = UItemSlot();
						ItemSlots[i] = &NewItemSlot;

						// Event to update items
						if(UGameHUD* GameHUD = PlayerController->GetGameHUD())
						{
							DrawInventory(GameHUD);
						}

						return;
					}
				}
			}
		}
	}
}

void UInventoryComponent::Swap(uint32 IndexOne, uint32 IndexTwo)
{
	UItemSlot* FirstSlot = ItemSlots[IndexOne];
	UItemSlot* SecondSlot = ItemSlots[IndexTwo];

	if(FirstSlot == SecondSlot)
	{
		return;
	}

	if(SecondSlot->Item != nullptr)
	{
		if(FirstSlot->Item == SecondSlot->Item)
		{
			uint32 SecondSlotRemainingSpace = SecondSlot->Item->GetMaxStack() - SecondSlot->Quantity;

			if(FirstSlot->Quantity <= SecondSlotRemainingSpace)
			{
				ItemSlots[IndexTwo]->Quantity += FirstSlot->Quantity;
				UItemSlot NewItemSlot = UItemSlot();
				ItemSlots[IndexOne] = &NewItemSlot;

				// Event to update items
				if(UGameHUD* GameHUD = PlayerController->GetGameHUD())
				{
					DrawInventory(GameHUD);
				}
				
				return;
			}
		}
	}

	ItemSlots[IndexOne] = SecondSlot;
	ItemSlots[IndexTwo] = FirstSlot;

	// Event to update items
	if(UGameHUD* GameHUD = PlayerController->GetGameHUD())
	{
		DrawInventory(GameHUD);
	}
}

void UInventoryComponent::PrintInventory() const
{
	for(UItemSlot* Slot : ItemSlots)
	{
		if(Slot->Item != nullptr)
		{
			UE_LOG(LogTemp,Warning,TEXT("Item Name: %s, Item Quantity: %u"),*Slot->Item->GetName(),Slot->Quantity);
		}
	}
}

void UInventoryComponent::DrawInventory(UGameHUD* GameHUD) const
{
	for(size_t i = 0; i < GameHUD->InventorySlots.Num(); i++)
	{
		if(GameHUD->InventorySlots[i])
		{
			UInventorySlot* SlotWidget = Cast<UInventorySlot>(GameHUD->InventorySlots[i]);

			if(SlotWidget)
			{
				if(ItemSlots[i] && ItemSlots[i]->Item)
				{
					SlotWidget->FillSlotInfo(ItemSlots[i]->Quantity,ItemSlots[i]->Item->GetIcon());
				}
			}
		}
	}
}


