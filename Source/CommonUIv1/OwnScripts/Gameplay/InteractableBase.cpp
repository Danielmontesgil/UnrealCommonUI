// Copyright 2023 Daniel Montes Gil.

// Base class for items that have a representation on world and can be collected for players

#include "InteractableBase.h"
#include "Kismet/GameplayStatics.h"
#include "ConsumableItem.h"

// Sets default values
AInteractableBase::AInteractableBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collision Mesh"));
	RootComponent = InteractableMesh;
}

// Called when the game starts or when spawned
void AInteractableBase::BeginPlay()
{
	Super::BeginPlay();

	ConsumableComponent = Cast<UConsumableItem>(GetComponentByClass(UConsumableItem::StaticClass()));
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
	return ConsumableComponent;
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





