#pragma once

#include "ItemDataBase.generated.h"

struct FItemData;

UCLASS()
class UItemDataBase : public UObject
{
	GENERATED_BODY()
public:
	static void LoadItems();
	static FItemData* GetItemByName(const FString& Name);
	static FItemData* GetRandomItem();

private:
	static TArray<FItemData*> Items;
	static bool IsLoaded;
	static void CheckStatus();
};
