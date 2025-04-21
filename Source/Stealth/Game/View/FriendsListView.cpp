// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "FriendsListView.h"
#include "MVVMViewModelBase.h"
#include "Components/VerticalBox.h"
#include "Stealth/StealthCharacter.h"
#include "View/MVVMView.h"

void UFriendsListView::AddFriendView()
{
	UClass* WidgetClass;
	if (!FriendWidgetClass.IsValid())
	{
		WidgetClass = FriendWidgetClass.LoadSynchronous();
	}
	else
	{
		WidgetClass = FriendWidgetClass.Get();
	}

	if (!WidgetClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Widget class failed loading"));
		return;
	}

	UUserWidget* NewSlot = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);

	if (NewSlot && FriendsVerticalBox)
	{
		FriendsVerticalBox->AddChild(NewSlot);
		FriendWidgets.Add(NewSlot);
	}

	NotifyFriendViewModel(FriendWidgets.Num() - 1);
}

void UFriendsListView::NativeOnActivated()
{
	Super::NativeOnActivated();

	AStealthCharacter* Character = Cast<AStealthCharacter>(GetOwningPlayerPawn());
	int32 FriendsAmount = 0;
	
	if (Character)
	{
		FriendsAmount = Character->GetFriendsAmount();
	}
	
	for (int i = FriendWidgets.Num(); i < FriendsAmount; i++)
	{
		AddFriendView();
	}
	
	for (int i = 0; i < FriendWidgets.Num(); i++)
	{
		NotifyFriendViewModel(i);
	}
}

void UFriendsListView::NotifyFriendViewModel(const int32 Index)
{
	AStealthCharacter* Character = Cast<AStealthCharacter>(GetOwningPlayerPawn());

	if(UMVVMView* InventorySlotView = FriendWidgets[Index]->GetExtension<UMVVMView>())
	{
		if (auto ViewModel = InventorySlotView->GetViewModel("FriendViewModel"))
		{
			if(UMVVMViewModelBase* FriendViewModel = Cast<UMVVMViewModelBase>(ViewModel.GetObject()))
			{
				Character->NotifyFriendViewModel(FriendViewModel, Index);
			}
		}
	}
}
