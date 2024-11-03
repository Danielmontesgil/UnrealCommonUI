// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UBUIManagerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UNREALBOOTCAMP_API UUBUIManagerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UI")
	void InstantiateWidget(const TSubclassOf<class UUBUserWidget> WidgetToCreateClass);
};
