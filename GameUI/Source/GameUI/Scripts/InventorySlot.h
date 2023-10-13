// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "InventorySlot.generated.h"

/**
 * 
 */
UCLASS()
class GAMEUI_API UInventorySlot : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	class UCommonTextBlock* ItemQuantity;
	
	UPROPERTY(meta=(BindWidget))
	class UCommonLazyImage* ItemIcon;
};
