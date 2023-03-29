// Copyright 2023 Daniel Montes Gil.

// Items that can be part of the Inventory and have price and max stack

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
UCLASS()
class COMMONUIV1_API UInventoryItem : public UItemBase
{
	GENERATED_BODY()
	
public:
	uint32 GetSellPrice() const;

	uint32 GetMaxStack() const;

	bool operator==(const UInventoryItem& A);

	bool operator!=(const UInventoryItem& A);
protected:
	UPROPERTY(EditAnywhere, Category = "Item Data")
	uint32 SellPrice = 1;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	uint32 MaxStack = 1;
};
