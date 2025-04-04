// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "FriendViewModel.generated.h"

enum class EFriendStatus : uint8;
/**
 * 
 */
UCLASS()
class STEALTH_API UFriendViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, FieldNotify)
	FString Name;

	UPROPERTY(BlueprintReadWrite, FieldNotify)
	EFriendStatus Status;

	UPROPERTY(BlueprintReadWrite, FieldNotify)
	FColor Color;

	UFUNCTION()
	void InitFriend(const FString& NewName, const EFriendStatus NewStatus);

	UFUNCTION()
	void SetFriendStatus(const EFriendStatus NewStatus);
};
