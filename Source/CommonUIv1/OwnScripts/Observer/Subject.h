// Copyright 2023 Daniel Montes Gil.

// Interface that allows us to keep reference to listeners in the Observer pattern

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Subject.generated.h"

class IObserver;

// This class does not need to be modified.
UINTERFACE()
class USubject : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class COMMONUIV1_API ISubject
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void Attach(FString eventType, IObserver* observer)=0;
	virtual void Detach(FString eventType, IObserver* observer)=0;
	virtual void Notify(FString eventType) const =0;
};
