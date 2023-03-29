// Copyright 2023 Daniel Montes Gil.

//Part of the View that shows each Slot on the inventory with its icon and quantity

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventorySlot.generated.h"

/**
 * 
 */
UCLASS()
class COMMONUIV1_API UInventorySlot : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* ItemAmount;
	
	UPROPERTY(meta=(BindWidget))
	class UImage* ItemIcon;

public:

	void FillSlotInfo(uint32 Quantity, UTexture2D* ItemImage) const;
};
