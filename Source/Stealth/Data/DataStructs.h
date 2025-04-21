#pragma once

#include "Engine/DataTable.h"
#include "DataStructs.generated.h"

enum class EFriendStatus : uint8;

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	FItemData() : Id("-1"){};
	
	FItemData(const FString& Id, const FString& Name, UTexture2D* Icon, const int SellPrice, const int MaxStack) :
	Id(Id), Name(Name), Icon(Icon), SellPrice(SellPrice), MaxStack(MaxStack){}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Icon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int SellPrice = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxStack = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UseText = FString("Does something, maybe?");
	
	bool operator==(const FItemData& Other) const
	{
		return Id == Other.Id;
	}

	bool operator!=(const FItemData& Other) const
	{
		return !(*this == Other);
	}
};

USTRUCT()
struct FFriendData
{
	GENERATED_BODY()

	UPROPERTY()
	FString Id;

	UPROPERTY()
	FString Name;

	UPROPERTY()
	EFriendStatus Status; 
};
