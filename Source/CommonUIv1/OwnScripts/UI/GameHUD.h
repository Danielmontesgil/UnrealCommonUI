// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CommonUIv1/OwnScripts/Observer/Observer.h"
#include "GameHUD.generated.h"

class UItemSlot;

/**
 * 
 */
UCLASS()
class COMMONUIV1_API UGameHUD : public UUserWidget, public IObserver
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
	virtual void Update() override;
};
