// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.h"
#include "ConsumableItem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMMONUIV1_API UConsumableItem : public UInventoryItem
{
	GENERATED_BODY()
	
public:
	virtual FString GetInfoDisplayText() override;

private:
	UPROPERTY(EditAnywhere, Category = "Consumable Item");
    FString UseText = FString("Does something, maybe?");
};
