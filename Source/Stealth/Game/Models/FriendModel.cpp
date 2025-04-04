// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "FriendModel.h"

#include "Stealth/Game/ViewModel/FriendViewModel.h"

UFriendModel::UFriendModel()
{
}

void UFriendModel::Init(const FString& InputId, const FString& InputName)
{
	Id = InputId;
	Name = InputName;
	Status = EFriendStatus::Disconnected;
}

void UFriendModel::SetFriendViewModel(UMVVMViewModelBase* ViewModel)
{
	if (ViewModel)
	{
		UFriendViewModel* InputFriendViewModel = Cast<UFriendViewModel>(ViewModel);
		if (InputFriendViewModel)
		{
			FriendViewModel = InputFriendViewModel;
			FriendViewModel->InitFriend(Name, Status);
		}
	}
}

void UFriendModel::ToggleStatus()
{
	if (FriendViewModel)
	{
		Status = Status == EFriendStatus::Disconnected ? EFriendStatus::Connected : EFriendStatus::Disconnected;
		FriendViewModel->SetFriendStatus(Status);
	}
}
