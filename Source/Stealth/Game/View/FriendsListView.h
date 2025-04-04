// © 2024 Daniel Montes Gil - dmontesgil@gmail.com All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FriendsListView.generated.h"

class UVerticalBox;
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
	TArray<UUserWidget*> FriendWidgets;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* FriendsVerticalBox;

protected:
	virtual void NativeOnActivated() override;
};
