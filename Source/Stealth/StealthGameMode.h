// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StealthGameMode.generated.h"

enum class EWidgetStack : uint8;
class UPlayerViewModel;
class UCommonActivatableWidget;

UCLASS(minimalapi)
class AStealthGameMode : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UCommonActivatableWidget> GameModeInitialWidgetClass;

	UPROPERTY(EditAnywhere)
	EWidgetStack InitialWidgetStack;

public:
	AStealthGameMode();

protected:
	virtual void BeginPlay() override;

private:	
	UFUNCTION()
	void OnHudLoaded() const;
};



