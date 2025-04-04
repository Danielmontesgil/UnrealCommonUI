// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "InventoryView.h"
#include "MVVMViewModelBase.h"
#include "Components/WrapBox.h"
#include "Stealth/StealthCharacter.h"
#include "View/MVVMView.h"

UWidget* UInventoryView::NativeGetDesiredFocusTarget() const
{
	if (InventorySlots.Num() > 0)
	{
		UUserWidget* FocusedSlot = InventorySlots[0];
		
		if (FocusedSlot && FocusedSlot->IsFocusable())
		{
			return FocusedSlot;
		}
	}

	return nullptr;
}

void UInventoryView::NativeConstruct()
{
	Super::NativeConstruct();

	if (!InventorySlotWidgetClass)
	{
		UE_LOG(LogTemp, Error, TEXT("InventorySlotWidgetClass is null"));
		return;
	}

	UClass* WidgetClass = InventorySlotWidgetClass.LoadSynchronous();
	if (!WidgetClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Widget class failed loading"));
		return;
	}

	if(InventorySlots.Num() <= 0)
	{
		for (int i = 0; i < 20; i++)
		{
			UUserWidget* NewSlot = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
			if (NewSlot && InventoryWrapBox)
			{
				InventoryWrapBox->AddChild(NewSlot);
				InventorySlots.Add(NewSlot);
			}
		}
	}
}

void UInventoryView::NativeOnActivated()
{
	Super::NativeOnActivated();

	for (int i = 0; i < InventorySlots.Num(); i++)
	{
		if(UMVVMView* InventorySlotView = InventorySlots[i]->GetExtension<UMVVMView>())
		{
			if (auto ViewModel = InventorySlotView->GetViewModel("InventorySlotViewModel"))
			{
				if(UMVVMViewModelBase* InventorySlotViewModel = Cast<UMVVMViewModelBase>(ViewModel.GetObject()))
				{
					NotifySlotViewModelCreation(InventorySlotViewModel, i);
				}
			}
		}
	}
}

void UInventoryView::NotifySlotViewModelCreation(UMVVMViewModelBase* ViewModel, const int Index)
{
	if(AStealthCharacter* Character = Cast<AStealthCharacter>(GetOwningPlayerPawn()))
	{
		Character->NotifySlotViewModel(ViewModel, Index);
	}
}
