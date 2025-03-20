// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#include "ItemDataBase.h"
#include "../../Data/DataStructs.h"

TArray<FItemData*> UItemDataBase::Items;
bool UItemDataBase::IsLoaded = false;

void UItemDataBase::LoadItems()
{
	const FString DataTablePath = FPaths::Combine(TEXT("/Game/Stealth/Data/DT_ItemData"));
	const FSoftObjectPath DataTableReference(DataTablePath);

	if(const UDataTable* DataTable = Cast<UDataTable>(DataTableReference.TryLoad()))
	{
		DataTable->GetAllRows("",Items);
		IsLoaded = true;
		UE_LOG(LogTemp, Display, TEXT("Data Table was loaded from: %s"), *DataTablePath);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Data Table was not loaded from: %s"), *DataTablePath);
	}
}

FItemData* UItemDataBase::GetItemByName(const FString& Name)
{
	CheckStatus();

	if(const auto FoundItem = Items.FindByPredicate([&](const FItemData* Item)
	{
		return Item->Name == Name;
	}))
	{
		return *FoundItem;
	}

	return nullptr;
}

FItemData* UItemDataBase::GetRandomItem()
{
	CheckStatus();

	if(Items.Num() <= 0)
	{
		return nullptr;
	}
	
	if(Items.Num() == 1)
	{
		return Items[0];
	}
	
	const int RandomIndex = rand() % Items.Num();

	return Items[RandomIndex];
}

void UItemDataBase::CheckStatus()
{
	if(!IsLoaded)
	{
		UE_LOG(LogTemp, Warning, TEXT("Items is not loaded, loading it..."));
		LoadItems();	
	}
}
