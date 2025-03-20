// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "StealthGameGameMode.h"
#include "Items/ItemDataBase.h"

void AStealthGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	UItemDataBase::LoadItems();
}
