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

	// This just to test how to add widgets using Synchronize Properties
	
	// virtual void SynchronizeProperties() override;
	//
	// UPROPERTY(EditAnywhere, Category = "Inventory Panel")
	// TSubclassOf<UUserWidget> InventorySlotClass = nullptr;
	//
	// UPROPERTY(EditAnywhere, Category = "Inventory Panel")
	// int32 Columns = 4;
	//
	// UPROPERTY(EditAnywhere, Category = "Inventory Panel")
	// int32 Rows = 3;
	//
	// UPROPERTY(BlueprintReadOnly, Category = "Inventory Panel",
	// 	meta=(BindWidget))
	// class UUniformGridPanel* Grid = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UUserWidget*> InventorySlots;

protected:
	
	UPROPERTY(meta=(BindWidget))
	class UCanvasPanel* CanvasContainer;
	
};
