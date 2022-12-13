// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ViewModelable.h"
#include "InventoryViewModel.generated.h"

class ACommonUIv1Character;
class UInventoryComponent;
class UItemSlot;

DECLARE_MULTICAST_DELEGATE(FOnShowInventorySignature)
DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnDrawInventorySlotSignature, uint32, uint32, UTexture2D*)

/**
 * 
 */
UCLASS()
class COMMONUIV1_API UInventoryViewModel : public UObject, public IViewModelable
{
	GENERATED_BODY()

public:
	FOnShowInventorySignature OnShowInventoryDelegate;
	FOnDrawInventorySlotSignature OnDrawInventorySlotDelegate;
	
	void Init(const ACommonUIv1Character* Character);
private:
	virtual void RegisterDelegates() override;
	virtual void UpdateUI() override;
	void OnInventoryUpdated(bool NeedToOpenInventory, const TArray<UItemSlot*>& ItemSlots);
	
	UPROPERTY()
	UInventoryComponent* Inventory;
	UPROPERTY()
	TArray<UItemSlot*> InventoryData;
};
