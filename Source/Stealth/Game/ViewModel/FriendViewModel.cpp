// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "FriendViewModel.h"
#include "Stealth/Game/Models/FriendModel.h"

void UFriendViewModel::InitFriend(const FString& NewName, const EFriendStatus NewStatus)
{
	UE_MVVM_SET_PROPERTY_VALUE(Name, NewName);
	SetFriendStatus(NewStatus);
}

void UFriendViewModel::SetFriendStatus(const EFriendStatus NewStatus)
{
	UE_MVVM_SET_PROPERTY_VALUE(Status, NewStatus);
	FColor NewColor;
	switch (NewStatus)
	{
	case EFriendStatus::Connected:
		NewColor = FColor::Green;
		break;
	case EFriendStatus::Away:
		NewColor = FColor::Yellow;
		break;
	default:
		NewColor = FColor::Red;
		break;
	}

	UE_MVVM_SET_PROPERTY_VALUE(Color, NewColor);
	
}
