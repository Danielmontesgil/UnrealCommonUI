// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "UObject/Object.h"
#include "InventoryItem.generated.h"

struct FItemData;
/**
 * 
 */
UCLASS()
class STEALTH_API UInventoryItem : public UItemBase
{
	GENERATED_BODY()

public:

	UInventoryItem();
	void Init(const FItemData& ItemData);

	virtual FString GetId() override { return Id; }
	virtual FString GetName() override { return Name; }
	virtual UTexture2D* GetIcon() override { return Icon; }
	virtual FString GetUseText() override { return UseText; }
	
	UFUNCTION()
	virtual uint32 GetSellPrice() { return SellPrice; }

	UFUNCTION()
	virtual uint32 GetMaxStack() { return  MaxStack; }

	UFUNCTION()
	virtual uint32 GetItemQuantity () { return ItemQuantity; }

protected:
	UPROPERTY(EditAnywhere)
	uint32 SellPrice;

	UPROPERTY(EditAnywhere)
	uint32 MaxStack;

	UPROPERTY(EditAnywhere)
	uint32 ItemQuantity;
};
