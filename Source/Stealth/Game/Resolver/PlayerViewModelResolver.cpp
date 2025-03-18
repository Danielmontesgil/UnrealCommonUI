// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "PlayerViewModelResolver.h"
#include "Blueprint/UserWidget.h"
#include "Stealth/StealthCharacter.h"
#include "Stealth/Game/ViewModel/PlayerViewModel.h"

UObject* UPlayerViewModelResolver::CreateInstance(const UClass* ExpectedType, const UUserWidget* UserWidget, const UMVVMView* View) const
{
	if (!UserWidget)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerVMResolver: Invalid UserWidget"));
		return nullptr;
	}

	AStealthCharacter* Pawn = Cast<AStealthCharacter>(UserWidget->GetOwningPlayerPawn());
	if (!Pawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player Pawn found in PlayerVMResolver"));
		return nullptr;
	}

	return Pawn->GetPlayerViewModel();
}

#if WITH_EDITOR
bool UPlayerViewModelResolver::DoesSupportViewModelClass(const UClass* Class) const
{
	return Class->IsChildOf(UPlayerViewModel::StaticClass());
}
#endif
