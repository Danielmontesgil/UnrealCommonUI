// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FriendsListView.generated.h"

/**
 * 
 */
UCLASS()
class STEALTH_API UFriendsListView : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSoftClassPtr<UUserWidget> FriendWidgetClass;

	UPROPERTY(BlueprintReadOnly)
	TArray<UUserWidget*> Friends;

protected:
	virtual void NativeConstruct() override;
};
