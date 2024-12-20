// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CommonUIv1PlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UNiagaraSystem;
class UItemSlot;
class UGameHUD;
class AItemSpawner;

DECLARE_DELEGATE_OneParam(FOnItemAddedSignature, UItemSlot*);
DECLARE_MULTICAST_DELEGATE(FOnInventoryPressedSignature)

UCLASS()
class ACommonUIv1PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ACommonUIv1PlayerController();
	
	FOnItemAddedSignature OnItemAddedDelegate;
	FOnInventoryPressedSignature OnInventoryPressedDelegate;

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;

	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;

	UGameHUD* GetGameHUD() const;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void BeginPlay() override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	virtual void InitGameHUD();
	// End PlayerController interface

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	void OnTouchPressed(const ETouchIndex::Type FingerIndex, const FVector Location);
	void OnTouchReleased(const ETouchIndex::Type FingerIndex, const FVector Location);
	void OnPickPressed();
	void OnInventoryPressed();

private:
	bool bInputPressed; // Input is bring pressed
	bool bIsTouch; // Is it a touch device
	float FollowTime; // For how long it has been pressed

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> GameHUDClass;

	UPROPERTY(EditAnywhere)
	float PickRange = 200.f;

	UPROPERTY()
	UGameHUD* GameHUD;

	UPROPERTY()
	AItemSpawner* ItemSpawner;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AItemSpawner> ItemSpawnerClass;
};


