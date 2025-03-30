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
	virtual int32 GetSellPrice() { return SellPrice; }

	UFUNCTION()
	virtual int32 GetMaxStack() { return  MaxStack; }

	UFUNCTION()
	virtual int32 GetItemQuantity () { return ItemQuantity; }

	UFUNCTION()
	virtual void ModifyItemQuantity(const int32 Quantity) { ItemQuantity += Quantity; }; 

protected:
	UPROPERTY(EditAnywhere)
	int32 SellPrice;

	UPROPERTY(EditAnywhere)
	int32 MaxStack;

	UPROPERTY(EditAnywhere)
	int32 ItemQuantity;
};
