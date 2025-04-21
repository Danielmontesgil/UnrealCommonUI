// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InventorySlotModel.generated.h"

class UMVVMViewModelBase;
class UInventorySlotViewModel;
class UInventoryItem;
/**
 * 
 */
UCLASS()
class STEALTH_API UInventorySlotModel : public UObject
{
	GENERATED_BODY()

public:
	UInventorySlotModel();

	UFUNCTION()
	void Init(UInventoryItem* ItemInSlot);

	UFUNCTION()
	void SetSlotViewModel(UMVVMViewModelBase* ViewModel);

	UFUNCTION()
	void UpdateView();
	
	UFUNCTION(BlueprintCallable)
	UInventoryItem* GetInventoryItem();

private:
	UPROPERTY()
	UInventoryItem* InventoryItem;

	UPROPERTY()
	UInventorySlotViewModel* SlotViewModel;
};
