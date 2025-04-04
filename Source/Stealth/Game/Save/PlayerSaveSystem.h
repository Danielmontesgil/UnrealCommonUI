// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlayerSaveSystem.generated.h"

class UFriendModel;
class UInventoryItem;
/**
 * 
 */
UCLASS()
class STEALTH_API UPlayerSaveSystem : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<UFriendModel*> Friends;

	UPROPERTY()
	TArray<UInventoryItem*> Inventory;
};
