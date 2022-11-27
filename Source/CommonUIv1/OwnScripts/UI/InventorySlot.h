// Fill out your copyright notice in the Description page of Project Settings.

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
