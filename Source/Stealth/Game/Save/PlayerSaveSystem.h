// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlayerSaveSystem.generated.h"

struct FFriendData;
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
	TArray<FFriendData> Friends;

	UPROPERTY()
	TArray<UInventoryItem*> Inventory;
};
