#include "ItemDataBase.h"
#include <random>

TArray<FItemData*> ItemDataBase::Items;
bool ItemDataBase::IsLoaded = false;

void ItemDataBase::LoadItems()
{
	const FString DataTablePath = FPaths::Combine(TEXT("/Game/Dani/Blueprints/ItemData"));
	const FSoftObjectPath DataTableReference(DataTablePath);

	if(const UDataTable* DataTable = Cast<UDataTable>(DataTableReference.TryLoad()))
	{
		DataTable->GetAllRows("",Items);
		IsLoaded = true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Data Table was not loaded from: %s"), *DataTablePath);
	}
}

FItemData* ItemDataBase::GetItemByName(const FString& Name)
{
	CheckStatus();

	if(const auto FoundItem = Items.FindByPredicate([&](const FItemData* item)
	{
		return item->Name == Name;
	}))
	{
		return *FoundItem;
	}

	return nullptr;
}

FItemData* ItemDataBase::GetRandomItem()
{
	CheckStatus();
	
	if(Items.Num() == 1)
	{
		return Items[0];
	}
	
	const int randomIndex = rand() % Items.Num();

	// Get the random object from the array
	return Items[randomIndex];
}

void ItemDataBase::CheckStatus()
{
	if(!IsLoaded)
	{
		UE_LOG(LogTemp, Warning, TEXT("Items is not loaded, loading it..."));
		LoadItems();	
	}
}
