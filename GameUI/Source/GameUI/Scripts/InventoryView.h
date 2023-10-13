// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIWidgetBase.h"
#include "InventoryView.generated.h"

/**
 * 
 */
UCLASS()
class GAMEUI_API UInventoryView : public UUIWidgetBase
{
	GENERATED_BODY()

public:

	UInventoryView(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UCommonActivatableWidget*> InventorySlots;
};
