// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "InventoryView.generated.h"

class UMVVMViewModelBase;
/**
 * 
 */
UCLASS()
class STEALTH_API UInventoryView : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UUserWidget*> InventorySlots;

private:
	UFUNCTION(BlueprintCallable)
	void NotifySlotViewModelCreation(UMVVMViewModelBase* ViewModel, const int Index);
};
