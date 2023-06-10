// Copyright Epic Games, Inc. All Rights Reserved.

#include "CommonUIv1PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "CommonUIv1Character.h"
#include "OwnScripts/Gameplay/InteractableBase.h"
#include "OwnScripts/Gameplay/ItemSlot.h"
#include "Blueprint/UserWidget.h"
#include "OwnScripts/Gameplay/ConsumableItem.h"
#include "OwnScripts/Gameplay/ItemDataBase.h"
#include "OwnScripts/UI/GameHUD.h"

ACommonUIv1PlayerController::ACommonUIv1PlayerController()
{
	bEnableMouseOverEvents = true;
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

UGameHUD* ACommonUIv1PlayerController::GetGameHUD() const
{
	return Cast<UGameHUD>(GameHUD);
}

void ACommonUIv1PlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitGameHUD();

	ItemDataBase::LoadItems();
}

void ACommonUIv1PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if(bInputPressed)
	{
		FollowTime += DeltaTime;

		// Look for the touch location
		FVector HitLocation = FVector::ZeroVector;
		FHitResult Hit;
		if(bIsTouch)
		{
			GetHitResultUnderFinger(ETouchIndex::Touch1, ECC_Visibility, true, Hit);
		}
		else
		{
			GetHitResultUnderCursor(ECC_Visibility, true, Hit);
		}
		HitLocation = Hit.Location;

		// Direct the Pawn towards that location
		APawn* const MyPawn = GetPawn();
		if(MyPawn)
		{
			FVector WorldDirection = (HitLocation - MyPawn->GetActorLocation()).GetSafeNormal();
			MyPawn->AddMovementInput(WorldDirection, 1.f, false);
		}
	}
	else
	{
		FollowTime = 0.f;
	}
}

void ACommonUIv1PlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ACommonUIv1PlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ACommonUIv1PlayerController::OnSetDestinationReleased);
	InputComponent->BindAction("Pick", IE_Pressed, this, &ACommonUIv1PlayerController::OnPickPressed);
	InputComponent->BindAction("Inventory", IE_Pressed, this, &ACommonUIv1PlayerController::OnInventoryPressed);
	
	// support touch devices 
	InputComponent->BindTouch(IE_Pressed, this, &ACommonUIv1PlayerController::OnTouchPressed);
	InputComponent->BindTouch(IE_Released, this, &ACommonUIv1PlayerController::OnTouchReleased);

}

void ACommonUIv1PlayerController::InitGameHUD()
{
	if(GameHUD)
	{
		GameHUD->RemoveFromParent();
		GameHUD=nullptr;
		return;
	}
	
	GameHUD = Cast<UGameHUD>(CreateWidget(this,GameHUDClass));

	if(GameHUD)
	{
		GameHUD->AddToViewport();
		GameHUD->SetOwningPlayer(this);
		GameHUD->Init(Cast<ACommonUIv1Character>(GetCharacter())->GetInventoryComponent());
	}
}

void ACommonUIv1PlayerController::OnSetDestinationPressed()
{
	// We flag that the input is being pressed
	bInputPressed = true;
	// Just in case the character was moving because of a previous short press we stop it
	StopMovement();
}

void ACommonUIv1PlayerController::OnSetDestinationReleased()
{
	// Player is no longer pressing the input
	bInputPressed = false;

	// If it was a short press
	if(FollowTime <= ShortPressThreshold)
	{
		// We look for the location in the world where the player has pressed the input
		FVector HitLocation = FVector::ZeroVector;
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, true, Hit);
		HitLocation = Hit.Location;

		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, HitLocation);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, HitLocation, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}
}

void ACommonUIv1PlayerController::OnTouchPressed(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	bIsTouch = true;
	OnSetDestinationPressed();
}

void ACommonUIv1PlayerController::OnTouchReleased(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	bIsTouch = false;
	OnSetDestinationReleased();
}

void ACommonUIv1PlayerController::OnPickPressed()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, true, Hit);

	UE_LOG(LogTemp,Warning,TEXT("Presed"));
	
	if(AInteractableBase* Interactable = Cast<AInteractableBase>(Hit.GetActor()))
	{
		const ACommonUIv1Character* PlayerActor = Cast<ACommonUIv1Character>(GetPawn());
		const FVector InteractableLocation = Interactable->GetActorLocation();
		const double DistanceToInteractable = FVector::Dist(PlayerActor->GetActorLocation(),InteractableLocation);

		if(PlayerActor && DistanceToInteractable < PickRange)
		{
			if(UConsumableItem* InventoryItem = Interactable->GetConsumable())
			{
				UItemSlot* ItemSlot = NewObject<UItemSlot>();
				ItemSlot->Item = InventoryItem;
				ItemSlot->Quantity = Interactable->GetItemQuantity();

				OnItemAddedDelegate.Execute(ItemSlot);
			}
			Interactable->OnInteract_Implementation();
		}
		else
		{
			UE_LOG(LogTemp,Warning,TEXT("Out of range to pick the object"));	
		}
	}
}

void ACommonUIv1PlayerController::OnInventoryPressed()
{	
	OnInventoryPressedDelegate.Broadcast();
}
