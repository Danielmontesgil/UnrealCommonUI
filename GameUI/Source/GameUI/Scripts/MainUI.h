// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "MainUI.generated.h"

class UGameHUD;

/**
 * 
 */
UCLASS()
class GAMEUI_API UMainUI : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	
	UMainUI(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(meta=(BindWidget))
	UCommonActivatableWidgetStack* GameStack;

	UPROPERTY(meta = (BindWidget))
	UCommonActivatableWidgetStack* MenuStack;
};
