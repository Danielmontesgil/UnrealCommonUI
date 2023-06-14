// Copyright 2023 Daniel Montes Gil.

// Base class for items that have a representation on world and can be collected for players

#include "InteractableBase.h"
#include "Kismet/GameplayStatics.h"
#include "ConsumableItem.h"
#include "ItemDataBase.h"

// Sets default values
AInteractableBase::AInteractableBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collision Mesh"));
	RootComponent = InteractableMesh;
	Item = UItemDataBase::GetRandomItem();
	Consumable = NewObject<UConsumableItem>();
	if(Item)
	{
		Consumable->Init(Item);
		ItemQuantity=Item->ItemQuantity;
	}
}

// Called when the game starts or when spawned
void AInteractableBase::BeginPlay()
{
	Super::BeginPlay();

	bItemCollected = false;
}

// Called every frame
void AInteractableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractableBase::OnInteract_Implementation()
{
	if(bItemCollected)
	{
		return;
	}
	
	bItemCollected = true;
	
	OnCollected();
}

uint32 AInteractableBase::GetItemQuantity() const
{
	return ItemQuantity;
}

UConsumableItem* AInteractableBase::GetConsumable() const
{
	return Consumable;
}

void AInteractableBase::OnCollected() const
{
	if(InteractableMesh)
	{
		InteractableMesh->SetVisibility(false);
		InteractableMesh->SetSimulatePhysics(false);
		InteractableMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}





