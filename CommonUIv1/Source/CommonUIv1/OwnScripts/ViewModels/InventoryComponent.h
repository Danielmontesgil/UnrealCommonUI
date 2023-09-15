// Copyright 2023 Daniel Montes Gil.

// This class is the ViewModel for the inventory system, it handles the events that come from the Player and the View
// it also communicates with the Model to updated the info properly

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
	// Inventory methods
	void Init(uint32 Size);
	void AddItem(UItemSlot* Slot) const;
	void RemoveAt(size_t SlotIndex) const;
	void RemoveItem(UItemSlot* Slot) const;
	void Swap(uint32 IndexOne, uint32 IndexTwo) const;

	//Inventory UI methods
	void UpdateUI() const;
	void OnInventoryOpened() const;

private:

	UPROPERTY()
	ACommonUIv1PlayerController* PlayerController;

	UPROPERTY(VisibleAnywhere, Category="Model", meta = (AllowPrivateAccess = "true"))
	class UInventoryModel* InventoryModel;
};
