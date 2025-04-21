// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "StealthActivatableWidget.h"

#include "InputActionValue.h"
#include "Stealth/StealthCharacter.h"

FReply UStealthActivatableWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	AStealthCharacter* Character = Cast<AStealthCharacter>(GetOwningPlayerPawn());

	if (Character == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Character is null. No action will be taken"));
	}
	
	if (InKeyEvent.GetKey() == EKeys::H)
	{
		UE_LOG(LogTemp, Warning, TEXT("Receive Item"));
		Character->ReceiveItem(FInputActionValue());
		return FReply::Handled();
	}
	if (InKeyEvent.GetKey() == EKeys::K)
	{
		UE_LOG(LogTemp, Warning, TEXT("Add Friend"));
		Character->AddFriend(FInputActionValue());
		return FReply::Handled();
	}
	if (InKeyEvent.GetKey() == EKeys::T)
	{
		UE_LOG(LogTemp, Warning, TEXT("Toggle Friend Status"));
		Character->ToggleFriendStatus(FInputActionValue());
		return FReply::Handled();
	}

	return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
	
}
