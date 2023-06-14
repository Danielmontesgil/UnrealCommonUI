#include "ItemSpawner.h"
#include "InteractableBase.h"
#include "CommonUIv1/OwnScripts/GenericStructs.h"
#include "Engine/DataTable.h"

AItemSpawner::AItemSpawner()
{
	UsedPositions.Reset();
	
	const FString DataTablePath = FPaths::Combine(TEXT("/Game/Dani/Data/ItemSpawiningInfo"));
	const FSoftObjectPath DataTableReference(DataTablePath);

	if(const UDataTable* DataTable = Cast<UDataTable>(DataTableReference.TryLoad()))
	{
		TArray<FItemPositionsData*> ItemPositionsData;
		DataTable->GetAllRows("",ItemPositionsData);
		for (const auto PositionsData : ItemPositionsData)
		{
			ItemPositions.Append(PositionsData->Positions);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Data Table was not loaded from: %s"), *DataTablePath);
	}
}

void AItemSpawner::SpawnItems(size_t ItemAmount)
{
	size_t counter = 0;

	while(counter < ItemAmount)
	{
		const int randomIndex = rand() % ItemPositions.Num();
		if(!UsedPositions.Contains(ItemPositions[randomIndex]))
		{
			if(AInteractableBase* Interactable = GetWorld()->SpawnActor<AInteractableBase>(InteractableClass))
			{
				Interactable->SetActorLocation(ItemPositions[randomIndex]);
			}

			UsedPositions.Add(ItemPositions[randomIndex]);
			counter++;
		}
	}
}
