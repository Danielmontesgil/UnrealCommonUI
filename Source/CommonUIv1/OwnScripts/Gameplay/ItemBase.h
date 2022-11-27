// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.generated.h"

/**
 * 
 */
UCLASS()
class COMMONUIV1_API UItemBase : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UItemBase();
	virtual ~UItemBase();
	
	FString GetName() const;

	UTexture2D* GetIcon() const;

	virtual FString GetInfoDisplayText();

protected:
	UPROPERTY(EditAnywhere, Category = "Basic Info")
	FString Name;

	UPROPERTY(EditAnywhere, Category = "Basic Info")
	UTexture2D* Icon;
};
