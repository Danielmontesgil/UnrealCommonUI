// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryComponent.generated.h"

class UItemSlot;
class UInventoryItem;
class ACommonUIv1PlayerController;

DECLARE_MULTICAST_DELEGATE(FOnShowInventorySignature)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnDrawInventorySignature, const TArray<UItemSlot*>&)


UCLASS()
class COMMONUIV1_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

	FOnShowInventorySignature OnShowInventoryDelegate;
	FOnDrawInventorySignature OnDrawInventorySlotDelegate;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	virtual void Init(uint32 Size);
	
	virtual void AddItem(UItemSlot* Slot);
	
	virtual void RemoveAt(size_t SlotIndex);

	virtual void RemoveItem(UItemSlot* Slot);

	virtual void Swap(uint32 IndexOne, uint32 IndexTwo);

	void UpdateUI() const;

	void OnInventoryOpened() const;

private:

	UPROPERTY()
	ACommonUIv1PlayerController* PlayerController;

	UPROPERTY(VisibleAnywhere, Category="Model", meta = (AllowPrivateAccess = "true"))
	class UInventoryModel* InventoryModel;
};
