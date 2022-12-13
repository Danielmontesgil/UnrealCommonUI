// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ViewModelable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UViewModelable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COMMONUIV1_API IViewModelable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void RegisterDelegates() = 0;
	virtual void UpdateUI() = 0;
};
