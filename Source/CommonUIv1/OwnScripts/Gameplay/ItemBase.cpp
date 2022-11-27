// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"

UItemBase::UItemBase()
{
	Name = FString("Enter an item name");
	Icon = nullptr;
}

UItemBase::~UItemBase()
{
}

FString UItemBase::GetName() const
{
	return Name;
}

UTexture2D* UItemBase::GetIcon() const
{
	return Icon;
}

FString UItemBase::GetInfoDisplayText()
{
	return FString(TEXT("You should not be seen this"));
}
