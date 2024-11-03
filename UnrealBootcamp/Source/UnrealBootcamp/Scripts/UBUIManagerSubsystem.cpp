// Fill out your copyright notice in the Description page of Project Settings.

#include "UBUIManagerSubsystem.h"
#include "Blueprint/UserWidget.h"

void UUBUIManagerSubsystem::InstantiateWidget(const TSubclassOf<class UUserWidget> MainMenuClass)
{	
	if(UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), MainMenuClass))
	{
		Widget->AddToViewport();
	}
}
