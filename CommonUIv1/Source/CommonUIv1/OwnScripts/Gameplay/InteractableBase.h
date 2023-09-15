// Copyright 2023 Daniel Montes Gil.

// Base class for items that have a representation on world and can be collected for players

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableBase.generated.h"

class UConsumableItem;
struct FItemData;

UCLASS()
class COMMONUIV1_API AInteractableBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	bool bItemCollected;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interact")
	void OnInteract();
	virtual void OnInteract_Implementation();
	virtual UConsumableItem* GetConsumable() const;
	virtual uint32 GetItemQuantity() const;

private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* InteractableMesh;

	FItemData* Item;
	
	UPROPERTY(VisibleAnywhere, Category="Item Data")
	UConsumableItem* Consumable;
	
	UPROPERTY(EditAnywhere,  Category="Item Data")
	uint32 ItemQuantity;

	void OnCollected() const;
};
