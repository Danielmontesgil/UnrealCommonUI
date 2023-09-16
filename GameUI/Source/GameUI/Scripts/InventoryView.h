// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "InventoryView.generated.h"

/**
 * 
 */
UCLASS()
class GAMEUI_API UInventoryView : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UCommonActivatableWidget*> InventorySlots;
	
};
