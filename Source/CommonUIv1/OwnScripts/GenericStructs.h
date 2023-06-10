#pragma once

#include "Engine/DataTable.h"
#include "GenericStructs.generated.h"

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SellPrice = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxStack = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ItemQuantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UseText = FString("Does something, maybe?");
};
