// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class STEALTH_API UItemBase : public UObject
{
	GENERATED_BODY()

public:
	UItemBase();

	UFUNCTION()
	virtual FString GetId() PURE_VIRTUAL(UItemBase::GetId, return "";)

	UFUNCTION()
	virtual FString GetName() PURE_VIRTUAL(UItemBase::GetName, return "";)

	UFUNCTION()
	virtual UTexture2D* GetIcon() PURE_VIRTUAL(UItemBase::GetIcon, return nullptr;)

	UFUNCTION()
	virtual FString GetUseText() PURE_VIRTUAL(UItemBase::GetUseText, return "";)


protected:
	UPROPERTY(EditAnywhere)
	FString Id;
	
	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere)
	FString UseText;
};
