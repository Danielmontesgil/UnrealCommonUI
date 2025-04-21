// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Game/Models/FriendsListModel.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "StealthCharacter.generated.h"

class UFriendsListView;
class UFriendsListModel;
class UInventoryModel;
class UCommonActivatableWidget;
class UPlayerViewModel;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UMVVMViewModelBase;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AStealthCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InventoryAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ReceiveItemAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* FriendsListAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* AddFriendAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ToggleFriendStatusAction;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCommonActivatableWidget> PlayerInventoryWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCommonActivatableWidget> FriendsListWidgetClass;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPlayerViewModel* PlayerViewModel;

	UPROPERTY(EditAnywhere)
	UInventoryModel* PlayerInventoryModel;

	UPROPERTY(EditAnywhere)
	UFriendsListModel* FriendsListModel;

	UPROPERTY()
	int32 MaxHealth;
	
	UPROPERTY()
	int32 Health;

	UPROPERTY()
	UFriendsListView* FriendsListView;

public:
	AStealthCharacter();

	virtual void BeginPlay() override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void OpenInventory(const FInputActionValue& Value);
	
	void OpenFriendsList(const FInputActionValue& Value);

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION()
	UPlayerViewModel* GetPlayerViewModel();

	UFUNCTION()
	void NotifySlotViewModel(UMVVMViewModelBase* ViewModel, const int Index) const;

	UFUNCTION()
	void NotifyFriendViewModel(UMVVMViewModelBase* ViewModel, const int Index) const;

	UFUNCTION()
	int32 GetFriendsAmount() const { return FriendsListModel->GetFriendsAmount(); }

	void AddFriend(const FInputActionValue& Value);

	void ToggleFriendStatus(const FInputActionValue& Value);

	void ReceiveItem(const FInputActionValue& Value);

};

