// Fill out your copyright notice in the Description page of Project Settings.

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
	void InstantiateWidget(const TSubclassOf<class UUserWidget> MainMenuClass);
};
