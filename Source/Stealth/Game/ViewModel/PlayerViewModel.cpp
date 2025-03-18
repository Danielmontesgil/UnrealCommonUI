// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.


#include "PlayerViewModel.h"

void UPlayerViewModel::SetPlayerHealth(const int32 NewPlayerHealth)
{
	if(const int32 NewHealthChange = NewPlayerHealth - PlayerHealth)
	{
		UE_MVVM_SET_PROPERTY_VALUE(HealthChange, NewHealthChange);
		if(NewHealthChange > 0)
		{
			UE_MVVM_SET_PROPERTY_VALUE(TextColor, FSlateColor(FColor::Green));
		}
		else
		{
			UE_MVVM_SET_PROPERTY_VALUE(TextColor, FSlateColor(FColor::Red));
		}
	}
	
	if(UE_MVVM_SET_PROPERTY_VALUE(PlayerHealth, NewPlayerHealth))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
	}
}

void UPlayerViewModel::SetMaxHealth(const int32 NewMaxHealth)
{
	if(UE_MVVM_SET_PROPERTY_VALUE(MaxHealth, NewMaxHealth))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
	}
}