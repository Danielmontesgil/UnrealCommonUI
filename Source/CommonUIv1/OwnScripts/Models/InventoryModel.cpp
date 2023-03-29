// Copyright 2023 Daniel Montes Gil.

// This is the Model that stores, and manipulate the Inventory Info

#include "InventoryModel.h"
#include "CommonUIv1/OwnScripts/Gameplay/ItemSlot.h"


UInventoryModel::UInventoryModel()
{
}

void UInventoryModel::Init(uint32 Size)
{
	ItemSlots.Init(NewObject<UItemSlot>() ,Size);
}

UItemSlot* UInventoryModel::GetSlotByIndex(const uint32 SlotIndex) const
{
	return ItemSlots[SlotIndex];
}

UItemSlot* UInventoryModel::AddItem(UItemSlot* Slot)
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

				return Slot;
			}
			
			UItemSlot* ItemSlot = NewObject<UItemSlot>();
			ItemSlot->Item = Slot->Item;
			ItemSlot->Quantity = Slot->Item->GetMaxStack();
			
			ItemSlots[i] = ItemSlot;

			Slot->Quantity -= Slot->Item->GetMaxStack();
		}
	}
	return Slot;
}

uint32 UInventoryModel::GetTotalQuantity(UInventoryItem* Item)
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

bool UInventoryModel::HasItem(UInventoryItem* Item) const
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

bool UInventoryModel::RemoveAt(size_t SlotIndex)
{
	if(SlotIndex < 0 || SlotIndex >= ItemSlots.Num() - 1)
	{
		return false;
	}

	UItemSlot ItemSlot = UItemSlot();
	ItemSlots[SlotIndex] = &ItemSlot;
	return true;
}

bool UInventoryModel::RemoveItem(UItemSlot* Slot)
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

						return true;
					}
				}
			}
		}
	}

	return false;
}

bool UInventoryModel::Swap(uint32 IndexOne, uint32 IndexTwo)
{
	UItemSlot* FirstSlot = ItemSlots[IndexOne];
	UItemSlot* SecondSlot = ItemSlots[IndexTwo];

	if(FirstSlot == SecondSlot)
	{
		return false;
	}

	if(SecondSlot->Item != nullptr)
	{
		if(FirstSlot->Item == SecondSlot->Item)
		{
			const uint32 SecondSlotRemainingSpace = SecondSlot->Item->GetMaxStack() - SecondSlot->Quantity;

			if(FirstSlot->Quantity <= SecondSlotRemainingSpace)
			{
				ItemSlots[IndexTwo]->Quantity += FirstSlot->Quantity;
				UItemSlot NewItemSlot = UItemSlot();
				ItemSlots[IndexOne] = &NewItemSlot;
				
				return true;
			}
		}
		return false;
	}

	ItemSlots[IndexOne] = SecondSlot;
	ItemSlots[IndexTwo] = FirstSlot;
	return true;
}
