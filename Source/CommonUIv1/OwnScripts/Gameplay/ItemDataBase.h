#pragma once

#include "CommonUIv1/OwnScripts/GenericStructs.h"

class ItemDataBase
{
public:
	static void LoadItems();
	static FItemData* GetItemByName(const FString& Name);
	static FItemData* GetRandomItem();

private:
	static TArray<FItemData*> Items;
	static bool IsLoaded;
	static void CheckStatus();
};
