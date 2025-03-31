// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "InventoryView.generated.h"

class UWrapBox;
class UMVVMViewModelBase;
/**
 * 
 */
UCLASS()
class STEALTH_API UInventoryView : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSoftClassPtr<UUserWidget> InventorySlotWidgetClass;

	UPROPERTY(BlueprintReadOnly)
	TArray<UUserWidget*> InventorySlots;

	UPROPERTY(meta = (BindWidget))
	UWrapBox* InventoryWrapBox;

protected:
	virtual void NativeConstruct() override;

	virtual void NativeOnActivated() override;
	
private:
	UFUNCTION(BlueprintCallable)
	void NotifySlotViewModelCreation(UMVVMViewModelBase* ViewModel, const int Index);
};
