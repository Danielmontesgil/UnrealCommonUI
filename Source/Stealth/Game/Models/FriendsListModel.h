// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FriendsListModel.generated.h"

class UMVVMViewModelBase;
class UFriendModel;
/**
 * 
 */
UCLASS()
class STEALTH_API UFriendsListModel : public UObject
{
	GENERATED_BODY()

public:
	UFriendsListModel();
	
	UFUNCTION()
	void AddFriend(UFriendModel* FriendToAdd);

	UFUNCTION()
	int32 GetFriendsAmount() const { return Friends.Num(); }

	UFUNCTION()
	void SetFriendViewModel(UMVVMViewModelBase* ViewModel, const int Index);

	UFUNCTION()
	void ToggleFriendStatus(const int Index);
	
private:
	UPROPERTY()
	TArray<UFriendModel*> Friends;

	UFUNCTION()
	void SaveFriends() const;
};
