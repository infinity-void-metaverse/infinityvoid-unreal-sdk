// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReadyPlayerMeTypes.h"
#include "GameFramework/Character.h"
#include "InfinityVoid/Data/S_UserDetail.h"
#include "Components/TextRenderComponent.h"
#include "InputAction.h"
#include "IVCharacterBase.generated.h"
class AIVInteractable;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCollisionChanged);

class USpringArmComponent;
class UCameraComponent;
UCLASS()
class INFINITYVOID_API AIVCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AIVCharacterBase(const FObjectInitializer& ObjectInitializer);

public:
	UPROPERTY(EditAnywhere, Category="Custom|Input") UInputAction* IA_Interact;
	UPROPERTY(EditAnywhere, Category="Custom|Input") UInputAction* IA_FlyMode;
	UPROPERTY(EditAnywhere, Category="Custom|Input") UInputAction* IA_Move;
	UPROPERTY(EditAnywhere, Category="Custom|Input") UInputAction* IA_Jump;
	UPROPERTY(EditAnywhere, Category="Custom|Input") UInputAction* IA_Sprint;
	UPROPERTY(EditAnywhere, Category="Custom|Input") UInputAction* IA_Look;
	UPROPERTY(EditAnywhere, Category="Custom|Input") UInputAction* IA_FirstPersonCamera;
	UPROPERTY(EditAnywhere, Category="Custom|Input") class UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Movement") class UZEZCharacterMovementComponent* ZEZCharacterMovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)	
	UTextRenderComponent* TR_UserName;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)	
	class UReadyPlayerMeComponent* ReadyPlayerMeComponent;

	UPROPERTY(EditAnywhere) float InteractableDistance = 5000;
	UPROPERTY(EditAnywhere) float DefaultWalkSpeed = 257;
	UPROPERTY(EditAnywhere) float SprintSpeed = 600;

	UPROPERTY(EditAnywhere) float DefaultSpringArmLength = 400;
	UPROPERTY(EditAnywhere) FVector DefaultSpringArmLocation = FVector(0,30, 73);
	UPROPERTY(EditAnywhere) float FirstPersonSpringArmLength = 0;
	UPROPERTY(EditAnywhere) FVector FirstSpringArmLocation = FVector(26,2, 73);
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bWeaponEquipped;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, BlueprintCallable) FOnCollisionChanged OnCollisionChanged;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated) bool bZEZDriving {false};
	bool bJumpAllowed {false};
	bool bSprintAllowed {true};
	void OnAvatarLoadComplete();
	void OnAvatarLoadFailed(FString ErrorMessage);

public:
	void OnInteractPressed(const FInputActionValue& InputActionValue);
	void OnFlyModePressed(const FInputActionValue& InputActionValue);
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void SetCharacterCanInterat(bool Value);

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;
	
	UFUNCTION()	void OnSprintStart();
	UFUNCTION()	void OnSprintEnd();
	
	FORCEINLINE void ResetInteraction() { InterfaceImplementableObj = nullptr; }
	UFUNCTION(BlueprintCallable) void SetPlayerVisibility(bool Value) const;
	UFUNCTION(BlueprintCallable) void OnWeaponEquipped(bool NewVisibility); 
	UFUNCTION(BlueprintCallable) void OnFirstPersonCamera();
	void UpdateCharacterDesiredControllerRotation(bool Value);
	UFUNCTION(BlueprintCallable) void OnFirstPersonCameraExit();
	UFUNCTION(Server, Reliable, BlueprintCallable) void S_UpdateUserDetail(FS_UserDetail _UserDetail);
	UFUNCTION(Server, Reliable, BlueprintCallable) void S_TeleportPlayer(FVector TargetLocation,FRotator TargetRotation);

protected:
	UPROPERTY(ReplicatedUsing = OnRep_OnUserDetailUpdate, BlueprintReadWrite) FS_UserDetail UserDetail;
	UPROPERTY(ReplicatedUsing = OnRep_bFlyModeChange, BlueprintReadWrite) bool bFlyMode = false;
	
	
protected:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
	UFUNCTION(Reliable, Client) void Client_PossessedByCalled();
	UFUNCTION(BlueprintImplementableEvent) bool CheckIfInteractable(FVector Start, FVector End, AActor*& Interacta);
	UFUNCTION(BlueprintImplementableEvent) void BP_OnUserDetailUpdate(FS_UserDetail _UserDetail);

private:
	AActor* InterfaceImplementableObj;
	//class IZEZInteractable* IInteractable;
	class AIVHUD* HUDObj;
	FTimerHandle CustomTickTimerHandler;
	FAvatarLoadCompleted AvatarLoadCompleted;
	FAvatarLoadFailed AvatarLoadFailed;
	bool CanInteract = true;
	
private:
	UFUNCTION(Server, Reliable) void S_ChangeMovementMode(bool bFlyModeValue);
	UFUNCTION(Server, Reliable) void S_UpdateOwnerOfInteractor(AActor* InteractableObj);
	UFUNCTION()	void OnRep_bFlyModeChange();
	UFUNCTION()	void OnRep_OnUserDetailUpdate();
	void OnUserDetailUpdate(FS_UserDetail _UserDetail);
	
	void CustomTick();
	void PostInteraction();
	void PostInteractionInterface();

};
