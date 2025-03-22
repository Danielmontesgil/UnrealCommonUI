// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InventoryModel.generated.h"

class UInventorySlotModel;
class UInventoryItem;
/**
 * 
 */
UCLASS()
class STEALTH_API UInventoryModel : public UObject
{
	GENERATED_BODY()

public:
	UInventoryModel();
	
	UFUNCTION()
	void AddItem(UInventoryItem* ItemToAdd);
	UFUNCTION()
	bool RemoveItem(const UInventoryItem* ItemToRemove);
	UFUNCTION()
	const UInventoryItem* GetItemByIndex(const uint32& ItemIndex) const;
	UFUNCTION()
	const uint32 GetItemQuantity(const UInventoryItem* Item);
	UFUNCTION()
	bool HasItem(const UInventoryItem* Item);
	UFUNCTION()
	const TArray<UInventorySlotModel*>& GetAllItems() const { return Items; }

private:
	UPROPERTY(VisibleAnywhere, Category="ItemSlots", meta = (AllowPrivateAccess = "true"))
	TArray<UInventorySlotModel*> Items;
};
