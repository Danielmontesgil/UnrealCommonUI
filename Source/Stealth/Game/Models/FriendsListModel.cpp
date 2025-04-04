// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "FriendsListModel.h"
#include "Kismet/GameplayStatics.h"
#include "Stealth/Game/Models/FriendModel.h"
#include "Stealth/Game/Save/PlayerSaveSystem.h"

UFriendsListModel::UFriendsListModel()
{
}

void UFriendsListModel::AddFriend(UFriendModel* FriendToAdd)
{
	Friends.Add(FriendToAdd);
	SaveFriends();
}

void UFriendsListModel::SetFriendViewModel(UMVVMViewModelBase* ViewModel, const int Index)
{
	if (ViewModel)
	{
		if (UFriendModel* Friend = Friends[Index])
		{
			Friend->SetFriendViewModel(ViewModel);
		}
	}
}

void UFriendsListModel::ToggleFriendStatus(const int Index)
{
	if (UFriendModel* Friend = Friends[Index])
	{
		Friend->ToggleStatus();
	}
}


void UFriendsListModel::SaveFriends() const
{
	UPlayerSaveSystem* PlayerSaveSystem = Cast<UPlayerSaveSystem>(UGameplayStatics::CreateSaveGameObject(UPlayerSaveSystem::StaticClass()));
	PlayerSaveSystem->Friends = Friends;
	UGameplayStatics::SaveGameToSlot(PlayerSaveSystem, TEXT("PlayerSaveSystem"), 0);
}
