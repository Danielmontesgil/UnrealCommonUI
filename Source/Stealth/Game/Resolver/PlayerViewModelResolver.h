// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "View/MVVMViewModelContextResolver.h"
#include "PlayerViewModelResolver.generated.h"

/**
 * 
 */
UCLASS()
class STEALTH_API UPlayerViewModelResolver : public UMVVMViewModelContextResolver
{
	GENERATED_BODY()

public:
	virtual UObject* CreateInstance(const UClass* ExpectedType, const UUserWidget* UserWidget, const UMVVMView* View) const override;

#if WITH_EDITOR
	virtual bool DoesSupportViewModelClass(const UClass* Class) const override;
#endif
};
