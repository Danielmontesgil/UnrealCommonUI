// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUIv1/OwnScripts/UI/GameHUD.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UItemSlot;
class UInventoryItem;
class ACommonUIv1PlayerController;

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnInventoryUpdatedSignature, bool, const TArray<UItemSlot*>&)

UCLASS()
class COMMONUIV1_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();
	UInventoryComponent(size_t Size);

	FOnInventoryUpdatedSignature OnInventoryUpdatedDelegate;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetSize(uint32 Size);

	virtual UItemSlot* GetSlotByIndex(const uint32 SlotIndex) const;
	
	virtual UItemSlot* AddItem(UItemSlot* Slot);

	virtual uint32 GetTotalQuantity(UInventoryItem* Item);

	virtual bool HasItem(UInventoryItem* Item) const;

	virtual void RemoveAt(size_t SlotIndex);

	virtual void RemoveItem(UItemSlot* Slot);

	virtual void Swap(uint32 IndexOne, uint32 IndexTwo);

	void OnInventoryOpened();

private:

	UPROPERTY()
	ACommonUIv1PlayerController* PlayerController;

	UPROPERTY(VisibleAnywhere, Category="ItemSlots", meta = (AllowPrivateAccess = "true"))
	TArray<UItemSlot*> ItemSlots;
};
