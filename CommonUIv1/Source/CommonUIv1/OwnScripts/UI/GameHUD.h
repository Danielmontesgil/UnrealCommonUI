// Copyright 2023 Daniel Montes Gil.

// This class is the View, it interacts with the ViewModel through events to show updated info

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHUD.generated.h"

class UItemSlot;

/**
 * 
 */
UCLASS()
class COMMONUIV1_API UGameHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	void Init(class UInventoryComponent* Inventory);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UUserWidget*> InventorySlots;

protected:
	
	UPROPERTY(meta=(BindWidget))
	class UVerticalBox* InventoryContainer;

	UPROPERTY()
	UInventoryComponent* InventoryViewModel;

private:
	void OnShowInventory() const;
	void OnDrawInventorySlot(const TArray<UItemSlot*>& ItemSlots) const;
};
