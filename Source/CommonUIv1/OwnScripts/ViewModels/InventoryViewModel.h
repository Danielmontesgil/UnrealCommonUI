// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ViewModelable.h"
#include "CommonUIv1/OwnScripts/UI/InventorySlot.h"
#include "UObject/Object.h"
#include "InventoryViewModel.generated.h"

class ACommonUIv1PlayerController;
class UInventoryComponent;
class UItemSlot;

DECLARE_MULTICAST_DELEGATE(FOnInventoryOpenedSignature)
DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnDrawInventorySlotSignature, uint32, uint32, UTexture2D*)

/**
 * 
 */
UCLASS()
class COMMONUIV1_API UInventoryViewModel : public UObject, public IViewModelable
{
	GENERATED_BODY()

public:
	FOnInventoryOpenedSignature OnInventoryOpenedDelegate;
	FOnDrawInventorySlotSignature OnDrawInventorySlotDelegate;
	
	void Init(ACommonUIv1PlayerController* Controller);
private:
	virtual void RegisterDelegates() override;
	virtual void UpdateUI() override;
	void OnInventoryOpened();

	UPROPERTY()
	ACommonUIv1PlayerController* PlayerController;
	UPROPERTY()
	UInventoryComponent* Inventory;
};
