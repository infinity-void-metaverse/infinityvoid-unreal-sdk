// Fill out your copyright notice in the Description page of Project Settings.


#include "IVCharacterBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "IVGameInstance.h"
#include "IVHUD.h"
#include "ReadyPlayerMeComponent.h"
#include "Components/TextRenderComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "InfinityVoid/Actors/Components/ZEZCharacterMovementComponent.h"
#include "InfinityVoid/Actors/Interactables/IVInteractable.h"
#include "..\Interfaces\IVIInteractable.h"
#include "InfinityVoid/Utils/ZEZUtils.h"
#include "Kismet/KismetStringLibrary.h"

// Sets default values
AIVCharacterBase::AIVCharacterBase(const FObjectInitializer& ObjectInitializer)
: Super (ObjectInitializer.SetDefaultSubobjectClass<UZEZCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	ZEZCharacterMovementComponent = Cast<UZEZCharacterMovementComponent>(GetCharacterMovement());
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = true; 

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
	FollowCamera->bUsePawnControlRotation = false;

	/*TR_UserName = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TR_UserName"));
	TR_UserName->SetupAttachment(RootComponent);
	TR_UserName->SetText(FText::FromString(""));*/

	ReadyPlayerMeComponent = CreateDefaultSubobject<UReadyPlayerMeComponent>(TEXT("ReadyPlayerMeComponent"));
	AddOwnedComponent(ReadyPlayerMeComponent);
}

// Called when the game starts or when spawned
void AIVCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	AvatarLoadCompleted.BindUFunction(this, FName("OnAvatarLoadComplete"));
	AvatarLoadCompleted.BindUFunction(this, FName("OnAvatarLoadFailed"));
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AIVCharacterBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AIVCharacterBase, bFlyMode);
	DOREPLIFETIME(AIVCharacterBase, UserDetail);
	DOREPLIFETIME(AIVCharacterBase, bZEZDriving);
}

void AIVCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if(Cast<APlayerController>(NewController))
	{
		Client_PossessedByCalled();
	}
}


void AIVCharacterBase::Client_PossessedByCalled_Implementation()
{
	HUDObj = Cast<AIVHUD>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	GetWorld()->GetTimerManager().SetTimer(CustomTickTimerHandler, this, &AIVCharacterBase::CustomTick, 0.2, true, 0.2);
	if(UIVGameInstance* GI = Cast<UIVGameInstance>(GetGameInstance()) )
	{
		if(GI->GetUserDetail().UserName.Len()>0 || GI->GetUserDetail().AvatarModelURL.Len()>0)
			S_UpdateUserDetail(GI->GetUserDetail());
		if(GI->CharacterSavedLoc!=FVector::ZeroVector)
		{
			S_TeleportPlayer(GI->CharacterSavedLoc, GI->CharacterSavedRot);
			//GPC->SetControlRotation(GI->CharacterSavedRot);
		}
		GGI->SetDeviceType(GGI->CurrentDeviceType);
		if(GGI->CurrentDeviceType==E_DeviceType::E_Mobile)
		{
			OnSprintStart();
		}
	}
}

void AIVCharacterBase::UnPossessed()
{
	Super::UnPossessed();
	AController* CurrentController = GetController();
	
	GetWorldTimerManager().ClearTimer(CustomTickTimerHandler);
}


void AIVCharacterBase::S_UpdateUserDetail_Implementation(FS_UserDetail _UserDetail)
{
	UserDetail = _UserDetail;
	OnUserDetailUpdate(_UserDetail);
}

void AIVCharacterBase::OnRep_bFlyModeChange()
{
	EMovementMode NewMovementMode = bFlyMode? EMovementMode::MOVE_Flying : MOVE_Walking;
	UCharacterMovementComponent* CharacterMovementComponent = GetCharacterMovement();
	CharacterMovementComponent->SetMovementMode(NewMovementMode);
	if(bFlyMode)
	{
		SetPlayerVisibility(false);
	}
	else
	{
		SetPlayerVisibility(true);
	}
	ZEZUtils::DM("MoveUpdated", this);
}

void AIVCharacterBase::OnRep_OnUserDetailUpdate()
{
	OnUserDetailUpdate(UserDetail);
}

void AIVCharacterBase::OnUserDetailUpdate(FS_UserDetail _UserDetail)
{
	ZEZUtils::DM("OnUserDetailUpdate *************" , this);

	if(_UserDetail.AvatarModelURL.Len()>0)
	{
		ZEZUtils::DM("Avatar model url laoding " + _UserDetail.AvatarModelURL, this);
		ReadyPlayerMeComponent->LoadNewAvatar(_UserDetail.AvatarModelURL,AvatarLoadCompleted, AvatarLoadFailed );
		if(GPC)
		{
			GPC->bShowMouseCursor = false;
		}
	}

	/*if(_UserDetail.UserName.Len()>0 && TR_UserName)
	{
		TR_UserName->SetText(FText::FromString(_UserDetail.UserName));
	}*/
	BP_OnUserDetailUpdate(_UserDetail);
}

void AIVCharacterBase::OnSprintStart()
{
	if(bSprintAllowed)
		ZEZCharacterMovementComponent->SprintPressed();
}

void AIVCharacterBase::OnSprintEnd()
{
	ZEZCharacterMovementComponent->SprintReleased();
}

void AIVCharacterBase::SetPlayerVisibility(bool Value) const
{
	if(Value)
		GetMesh()->SetVisibility(false, true);
	else
	{
		GetMesh()->SetVisibility(false, false);
	}
}

void AIVCharacterBase::OnWeaponEquipped(bool NewVisibility)
{
	bWeaponEquipped = NewVisibility;
}

void AIVCharacterBase::OnFirstPersonCamera()
{
	if(CameraBoom->TargetArmLength > 0)
	{
		CameraBoom->TargetArmLength = FirstPersonSpringArmLength;
		CameraBoom->SetRelativeLocation(FirstSpringArmLocation);
		ControllerSettingAccordingToCamera(true);
	}
	else
	{
		OnFirstPersonCameraExit();
	}
}

void AIVCharacterBase::ControllerSettingAccordingToCamera(bool Value)
{
	if(UCharacterMovementComponent* CMC = GetCharacterMovement())
	{
		CMC->bOrientRotationToMovement = !Value;
	}
	bUseControllerRotationYaw = Value;
}
 
void AIVCharacterBase::OnFirstPersonCameraExit()
{
	CameraBoom->TargetArmLength = DefaultSpringArmLength;
	CameraBoom->SetRelativeLocation(DefaultSpringArmLocation);
	ControllerSettingAccordingToCamera(false);

}

void AIVCharacterBase::C_FixControlRotation_Implementation(FRotator TargetRotation)
{
	ControllerSettingAccordingToCamera(true);
	GPC->SetControlRotation(TargetRotation);
	FTimerHandle TempHandle;
	GetWorld()->GetTimerManager().SetTimer(TempHandle, FTimerDelegate::CreateLambda( [this]()
	{
		ControllerSettingAccordingToCamera(false);
	} ), 1, false);
	
}

void AIVCharacterBase::S_TeleportPlayer_Implementation(FVector TargetLocation, FRotator TargetRotation)
{
	if(TargetLocation != FVector::ZeroVector)
	{
		SetActorLocation(TargetLocation);
		SetActorRotation(TargetRotation);
		C_FixControlRotation(TargetRotation);
	}
}

void AIVCharacterBase::CustomTick()
{
	if(HUDObj && this->IsLocallyControlled() && CanInteract)
	{
		//FHitResult HitResult;
		APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
		FVector Start = CameraManager->GetCameraLocation();
		FVector End = Start + CameraManager->GetActorForwardVector()* InteractableDistance;
		FCollisionQueryParams CollisionQueryParams;
		CollisionQueryParams.AddIgnoredActor(this);
		DrawDebugLine(GetWorld(), Start, End, FColor::Red);
		AActor* InteractingObject;
		//GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility, CollisionQueryParams);
		if(GetWorld() && CheckIfInteractable(Start, End, InteractingObject))
		{
			if(InterfaceImplementableObj == InteractingObject)
				return;
			if(AIVInteractable* InteractableObj = Cast<AIVInteractable>(InteractingObject))
			{
				if(!InteractableObj->bInteractable)
				{
					PostInteractionInterface();
					return;
				}
				HUDObj->UpdateInteractionText(InteractableObj->HUDInteractionText);
			}
			InterfaceImplementableObj = InteractingObject;
			HUDObj->UpdateCrosshair(true);
			HUDObj->SetInteractButtonVisibility(true);
		}
		else
		{
			PostInteractionInterface();
		}
	}
}


void AIVCharacterBase::PostInteractionInterface()
{
	if(InterfaceImplementableObj)
	{
		InterfaceImplementableObj = nullptr;
		HUDObj->UpdateCrosshair(false);
		HUDObj->SetInteractButtonVisibility(false);

	}
}

void AIVCharacterBase::S_ChangeMovementMode_Implementation(bool bFlyModeValue)
{
	bFlyMode = !bFlyMode;
	OnRep_bFlyModeChange();
}

void AIVCharacterBase::OnAvatarLoadComplete()
{
	ZEZUtils::DM("on avatar load complete", this);
}

void AIVCharacterBase::OnAvatarLoadFailed(FString ErrorMessage)
{
	ZEZUtils::DM("on avatar loading failed", this);
}

void AIVCharacterBase::OnInteractPressed(const FInputActionValue& InputActionValue)
{
	if(InterfaceImplementableObj)
	{
		S_UpdateOwnerOfInteractor(InterfaceImplementableObj);
		IIVIInteractable::Execute_OnInteraction(InterfaceImplementableObj);
	}
}

void AIVCharacterBase::S_UpdateOwnerOfInteractor_Implementation(AActor* InteractableObj)
{
	if(ZEZUtils::IsValid(InteractableObj, "Interactable obj not valid", this) && this)
		InteractableObj->SetOwner(this);
}

void AIVCharacterBase::OnFlyModePressed(const FInputActionValue& InputActionValue)
{
	S_ChangeMovementMode(bFlyMode);
}

void AIVCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent->BindAction(IA_Interact, ETriggerEvent::Started, this, &AIVCharacterBase::OnInteractPressed);
	EnhancedInputComponent->BindAction(IA_FlyMode, ETriggerEvent::Started, this, &AIVCharacterBase::OnFlyModePressed);
	EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &AIVCharacterBase::Jump);
	EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	EnhancedInputComponent->BindAction(IA_FirstPersonCamera, ETriggerEvent::Started, this, &AIVCharacterBase::OnFirstPersonCamera);
	EnhancedInputComponent->BindAction(IA_Sprint, ETriggerEvent::Triggered, this, &AIVCharacterBase::OnSprintStart);
	EnhancedInputComponent->BindAction(IA_Sprint, ETriggerEvent::Completed, this, &AIVCharacterBase::OnSprintEnd);
	EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AIVCharacterBase::Move);
	EnhancedInputComponent->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AIVCharacterBase::Look);
}

void AIVCharacterBase::Jump()
{
	if(bJumpAllowed)
		Super::Jump();
}

void AIVCharacterBase::Move(const FInputActionValue& Value)
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

void AIVCharacterBase::Look(const FInputActionValue& Value)
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

void AIVCharacterBase::SetCharacterCanInterat(bool Value)
{
	CanInteract = Value;
}
