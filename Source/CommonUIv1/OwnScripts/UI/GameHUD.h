// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class COMMONUIV1_API UGameHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	void Init();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UUserWidget*> InventorySlots;

protected:
	
	UPROPERTY(meta=(BindWidget))
	class UVerticalBox* InventoryContainer;

	UPROPERTY()
	class UInventoryViewModel* InventoryViewModel;

private:
	void OnShowInventory() const;
	void OnDrawInventorySlot(uint32 Index, uint32 Quantity, UTexture2D* ItemIcon) const;
};
