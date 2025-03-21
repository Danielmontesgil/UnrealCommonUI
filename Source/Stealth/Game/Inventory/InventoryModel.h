// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InventoryModel.generated.h"

class UInventoryItem;
/**
 * 
 */
UCLASS()
class STEALTH_API UInventoryModel : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AddItem(const UInventoryItem* ItemToAdd, const uint32 ItemAmount);
	UFUNCTION()
	bool RemoveItem(const UInventoryItem* ItemToRemove, const uint32 ItemAmount);
	UFUNCTION()
	const UInventoryItem* GetItemByIndex(const uint32& ItemIndex) const;
	UFUNCTION()
	const uint32 GetItemQuantity(const UInventoryItem* Item);
	UFUNCTION()
	bool HasItem(const UInventoryItem* Item);
	UFUNCTION()
	const TArray<UInventoryItem*>& GetAllItems() const { return Items; }

private:
	UPROPERTY(VisibleAnywhere, Category="ItemSlots", meta = (AllowPrivateAccess = "true"))
	TArray<UInventoryItem*> Items;
};
