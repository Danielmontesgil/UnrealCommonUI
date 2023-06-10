// Copyright 2023 Daniel Montes Gil.

// Specific inventory item that can be used from the Inventory

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "ConsumableItem.generated.h"

struct FItemData;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMMONUIV1_API UConsumableItem : public UInventoryItem
{
	GENERATED_BODY()
	
public:
	UConsumableItem();
	virtual FString GetInfoDisplayText() override;

private:
	UPROPERTY(EditAnywhere, Category = "Consumable Item");
    FString UseText = FString("Does something, maybe?");

	FItemData* Item;
};
