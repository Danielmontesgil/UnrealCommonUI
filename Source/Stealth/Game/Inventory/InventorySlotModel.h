// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InventorySlotModel.generated.h"

class UInventoryItem;
/**
 * 
 */
UCLASS()
class STEALTH_API UInventorySlotModel : public UObject
{
	GENERATED_BODY()

public:
	UInventorySlotModel();

	UFUNCTION()
	void Init(UInventoryItem* ItemInSlot) { InventoryItem = ItemInSlot; };
	
	UFUNCTION(BlueprintCallable)
	UInventoryItem* GetInventoryItem();

private:
	UInventoryItem* InventoryItem;
};
