// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FriendModel.generated.h"

class UFriendViewModel;
class UMVVMViewModelBase;

UENUM(BlueprintType)
enum class EFriendStatus : uint8
{
	Disconnected = 0,
	Away = 1,
	Connected = 2,
};

/**
 * 
 */
UCLASS()
class STEALTH_API UFriendModel : public UObject
{
	GENERATED_BODY()

public:
	UFriendModel();

	UFUNCTION()
	void Init(const FString& InputId, const FString& InputName);

	UFUNCTION()
	FString GetFriendId() const { return Id; }

	UFUNCTION()
	FString GetFriendName() const { return Name; }

	UFUNCTION()
	EFriendStatus GetFriendStatus() const { return Status; }

	UFUNCTION()
	void SetFriendViewModel(UMVVMViewModelBase* ViewModel);

	UFUNCTION()
	void ToggleStatus();

	UFUNCTION()
	void UpdateView();

private:
	UPROPERTY()
	FString Id;

	UPROPERTY()
	FString Name;

	UPROPERTY()
	EFriendStatus Status;

	UPROPERTY()
	UFriendViewModel* FriendViewModel;
};
