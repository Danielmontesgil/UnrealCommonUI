// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "FriendsListModel.h"
#include "Kismet/GameplayStatics.h"
#include "Stealth/Data/DataStructs.h"
#include "Stealth/Game/Models/FriendModel.h"
#include "Stealth/Game/Save/PlayerSaveSystem.h"

UFriendsListModel::UFriendsListModel()
{
}

void UFriendsListModel::Init()
{
	LoadFriends();
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
			Friend->UpdateView();
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
	for (const UFriendModel* Friend : Friends)
	{
		if (Friend)
		{
			FFriendData FriendData;
			FriendData.Id = Friend->GetName(); 
			FriendData.Name = Friend->GetFriendName();
			PlayerSaveSystem->Friends.Add(FriendData);
		}
	}
	UGameplayStatics::SaveGameToSlot(PlayerSaveSystem, TEXT("PlayerSaveSystem"), 0);
	UE_LOG(LogTemp, Warning, TEXT("Game Saved!"));
}

void UFriendsListModel::LoadFriends()
{
	if (UGameplayStatics::DoesSaveGameExist(TEXT("PlayerSaveSystem"), 0))
	{
		if (const UPlayerSaveSystem* LoadedGame = Cast<UPlayerSaveSystem>(UGameplayStatics::LoadGameFromSlot(TEXT("PlayerSaveSystem"), 0)))
		{
			UE_LOG(LogTemp, Warning, TEXT("Game Loaded!"));
			for (int i = 0; i < LoadedGame->Friends.Num(); i++)
			{
				UFriendModel* FriendToAdd = NewObject<UFriendModel>();
				FriendToAdd->Init(LoadedGame->Friends[i].Id, LoadedGame->Friends[i].Name);
				Friends.Add(FriendToAdd);
			}
		}
	}
}
