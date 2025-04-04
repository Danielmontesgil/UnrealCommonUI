// Copyright Epic Games, Inc. All Rights Reserved.

#include "StealthCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Data/DataStructs.h"
#include "Game/Models/InventoryModel.h"
#include "Game/Items/InventoryItem.h"
#include "Game/Items/ItemDataBase.h"
#include "Game/Models/FriendModel.h"
#include "Game/Models/FriendsListModel.h"
#include "Game/View/FriendsListView.h"
#include "Game/ViewModel/PlayerViewModel.h"
#include "General/MainHUD.h"
#include "General/View/StealthStackWidget.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AStealthCharacter

AStealthCharacter::AStealthCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	MaxHealth = 100;
	Health = MaxHealth;
}

void AStealthCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerInventoryModel = NewObject<UInventoryModel>(this);
	FriendsListModel = NewObject<UFriendsListModel>(this);

	if (FriendsListModel)
	{
		UE_LOG(LogTemp, Display, TEXT("FriendsListModel created"));
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void AStealthCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AStealthCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AStealthCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AStealthCharacter::Look);

		// Inventory
		EnhancedInputComponent->BindAction(InventoryAction, ETriggerEvent::Started, this, &AStealthCharacter::OpenInventory);
		// Testing Inventory
		EnhancedInputComponent->BindAction(ReceiveItemAction, ETriggerEvent::Started, this, &AStealthCharacter::ReceiveItem);

		// Fiends list
		EnhancedInputComponent->BindAction(FriendsListAction, ETriggerEvent::Started, this, &AStealthCharacter::OpenFriendsList);
		EnhancedInputComponent->BindAction(AddFriendAction, ETriggerEvent::Started, this, &AStealthCharacter::AddFriend);
		EnhancedInputComponent->BindAction(ToggleFriendStatusAction, ETriggerEvent::Started, this, &AStealthCharacter::ToggleFriendStatus);

	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AStealthCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AStealthCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AStealthCharacter::OpenInventory(const FInputActionValue& Value)
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if (PlayerController != nullptr)
	{
		AMainHUD* MainHUD = Cast<AMainHUD>(PlayerController->GetHUD());

		if (MainHUD != nullptr)
		{
			MainHUD->PushWidget(PlayerInventoryWidgetClass, EWidgetStack::OverlayStack);
		}
	}
}

void AStealthCharacter::ReceiveItem(const FInputActionValue& Value)
{
	FItemData ItemData = UItemDataBase::GetRandomItem();
	if (ItemData.Id != "-1")
	{
		UInventoryItem* ItemToAdd = NewObject<UInventoryItem>(this);
		ItemToAdd->Init(ItemData);
		ItemToAdd->ModifyItemQuantity(5);
		UE_LOG(LogTemp, Display, TEXT("Item with Id: %s added"), *(ItemToAdd->GetId()))

		if (PlayerInventoryModel != nullptr)
		{
			PlayerInventoryModel->AddItem(ItemToAdd);
		}
	}
}

void AStealthCharacter::OpenFriendsList(const FInputActionValue& Value)
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if (PlayerController != nullptr)
	{
		AMainHUD* MainHUD = Cast<AMainHUD>(PlayerController->GetHUD());

		if (MainHUD != nullptr)
		{
			FriendsListView = Cast<UFriendsListView>(MainHUD->PushWidget(FriendsListWidgetClass, EWidgetStack::OverlayStack));
		}
	}
}

void AStealthCharacter::AddFriend(const FInputActionValue& Value)
{
	UFriendModel* Friend = NewObject<UFriendModel>();
	
	if (FriendsListModel != nullptr)
	{
		int32 Num = FriendsListModel->GetFriendsAmount() + 1;
		Friend->Init(FString::Format(TEXT("F00{0}"), {Num}),FString::Format(TEXT("John{0}"), {Num}));
		FriendsListModel->AddFriend(Friend);
	}
}

void AStealthCharacter::ToggleFriendStatus(const FInputActionValue& Value)
{
	if (FriendsListModel)
	{
		FriendsListModel->ToggleFriendStatus(0);
	}
}

UPlayerViewModel* AStealthCharacter::GetPlayerViewModel()
{
	if(!PlayerViewModel)
	{
		PlayerViewModel = NewObject<UPlayerViewModel>();
		if(PlayerViewModel)
		{
			PlayerViewModel->SetMaxHealth(MaxHealth);
			PlayerViewModel->SetPlayerHealth(Health);
		}
	}
	
	return PlayerViewModel;
}

void AStealthCharacter::NotifySlotViewModel(UMVVMViewModelBase* ViewModel, const int Index) const
{
	PlayerInventoryModel->SetSlotViewModel(ViewModel, Index);
}

void AStealthCharacter::NotifyFriendViewModel(UMVVMViewModelBase* ViewModel, const int Index) const
{
	FriendsListModel->SetFriendViewModel(ViewModel, Index);
}
