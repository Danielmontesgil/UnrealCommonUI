// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InventoryModel.generated.h"

class UItemSlot;
class UInventoryItem;

/**
 * 
 */
UCLASS()
class COMMONUIV1_API UInventoryModel : public UObject
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryModel();
	
	void Init(uint32 Size);
	
	UItemSlot* AddItem(UItemSlot* Slot);
	
	UItemSlot* GetSlotByIndex(const uint32 SlotIndex) const;

	uint32 GetTotalQuantity(UInventoryItem* Item);

	bool HasItem(UInventoryItem* Item) const;

	bool RemoveAt(size_t SlotIndex);

	bool RemoveItem(UItemSlot* Slot);

	bool Swap(uint32 IndexOne, uint32 IndexTwo);

	const TArray<UItemSlot*>& GetInventory() const { return ItemSlots; }

private:
	UPROPERTY(VisibleAnywhere, Category="ItemSlots", meta = (AllowPrivateAccess = "true"))
	TArray<UItemSlot*> ItemSlots;
};
