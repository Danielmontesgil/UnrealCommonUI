// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
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
