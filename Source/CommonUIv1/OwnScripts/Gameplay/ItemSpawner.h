#pragma once

#include "ItemSpawner.generated.h"

class AInteractableBase;

UCLASS()
class COMMONUIV1_API AItemSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	AItemSpawner();
	void SpawnItems(size_t ItemAmount);
private:
	UPROPERTY()
	TArray<FVector> ItemPositions;
	UPROPERTY()
	TArray<FVector> UsedPositions;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AInteractableBase> InteractableClass;
};
