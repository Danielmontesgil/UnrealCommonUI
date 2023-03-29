// Copyright 2023 Daniel Montes Gil.

// This class is used on the Model to store all the items per Slot in the Inventory

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemSlot.generated.h"

class UInventoryItem;

/**
 * 
 */
UCLASS()
class COMMONUIV1_API UItemSlot : public UObject
{
	GENERATED_BODY()

public:
	UItemSlot();
	UItemSlot(UInventoryItem* Item, uint32 Quantity);
	
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess="true"))
	UInventoryItem* Item;
	UPROPERTY(VisibleAnywhere, meta=(AllowPrivateAccess="true"))
	uint32 Quantity;
};
