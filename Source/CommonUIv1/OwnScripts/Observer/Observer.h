﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Observer.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UObserver : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COMMONUIV1_API IObserver
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Update()=0;
};
