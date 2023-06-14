#pragma once

#include "CommonUIv1/OwnScripts/GenericStructs.h"
#include "ItemDataBase.generated.h"

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
