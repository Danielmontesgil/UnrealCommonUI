// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManagerSubsystem.h"
#include "Blueprint/UserWidget.h"

void UUIManagerSubsystem::CreateWidget(const TSubclassOf<class UUserWidget> MainMenuClass)
{
	if(UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld()->GetFirstPlayerController(), MainMenuClass))
	{
		Widget->AddToViewport();
	}
}
