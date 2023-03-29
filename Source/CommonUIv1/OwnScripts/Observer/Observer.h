// Copyright 2023 Daniel Montes Gil.

// Interface that handles the subscription to an event applying Observer pattern

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
