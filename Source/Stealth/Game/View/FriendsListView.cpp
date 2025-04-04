// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "FriendsListView.h"
#include "MVVMViewModelBase.h"
#include "Components/VerticalBox.h"
#include "Stealth/StealthCharacter.h"
#include "View/MVVMView.h"

void UFriendsListView::NativeOnActivated()
{
	Super::NativeOnActivated();

	AStealthCharacter* Character = Cast<AStealthCharacter>(GetOwningPlayerPawn());
	int32 FriendsAmount = 0;
	
	if (Character)
	{
		FriendsAmount = Character->GetFriendsAmount();
	}

	if (!FriendWidgetClass)
	{
		UE_LOG(LogTemp, Error, TEXT("FriendWidgetClass is null"));
		return;
	}

	UClass* WidgetClass = FriendWidgetClass.LoadSynchronous();
	if (!WidgetClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Widget class failed loading"));
		return;
	}


	for (int i = FriendWidgets.Num(); i < FriendsAmount; i++)
	{
		UUserWidget* NewSlot = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
		if (NewSlot && FriendsVerticalBox)
		{
			FriendsVerticalBox->AddChild(NewSlot);
			FriendWidgets.Add(NewSlot);
		}
	}

	for (int i = 0; i < FriendWidgets.Num(); i++)
	{
		if(UMVVMView* InventorySlotView = FriendWidgets[i]->GetExtension<UMVVMView>())
		{
			if (auto ViewModel = InventorySlotView->GetViewModel("FriendViewModel"))
			{
				if(UMVVMViewModelBase* FriendViewModel = Cast<UMVVMViewModelBase>(ViewModel.GetObject()))
				{
					Character->NotifyFriendViewModel(FriendViewModel, i);
				}
			}
		}
	}
	
}
