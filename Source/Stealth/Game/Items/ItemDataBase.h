// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemDataBase.generated.h"

struct FItemData;
/**
 * 
 */
UCLASS()
class STEALTH_API UItemDataBase : public UObject
{
	GENERATED_BODY()

public:
	static void LoadItems();
	static const FItemData& GetItemByName(const FString& Name);
	static const FItemData& GetRandomItem();
	static const FItemData GetFallbackItem();

private:
	static TArray<FItemData*> Items;
	static bool IsLoaded;
	static const FItemData FallbackItem;
	static void CheckStatus();
};
