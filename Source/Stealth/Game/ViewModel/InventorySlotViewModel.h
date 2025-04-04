// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "InventorySlotViewModel.generated.h"

class UInventoryItem;
/**
 * 
 */
UCLASS()
class STEALTH_API UInventorySlotViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, FieldNotify)
	UTexture2D* ItemIcon;

	UPROPERTY(BlueprintReadWrite, FieldNotify)
	int ItemAmount;

	UPROPERTY(BlueprintReadWrite, FieldNotify)
	ESlateVisibility AmountTextVisibility;

	UPROPERTY(BlueprintReadWrite, FieldNotify)
	ESlateVisibility SlotVisibility;

	UPROPERTY(BlueprintReadWrite, FieldNotify)
	bool IsSlotFocusable;

	UFUNCTION()
	void SetInventoryItem(UTexture2D* NewIcon, const int& NewItemAmount);
};
