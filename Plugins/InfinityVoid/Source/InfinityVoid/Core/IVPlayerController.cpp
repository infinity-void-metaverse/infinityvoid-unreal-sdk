// Fill out your copyright notice in the Description page of Project Settings.


#include "IVPlayerController.h"

#include "IVCharacterBase.h"
#include "IVGameInstance.h"
#include "IVPlayerState.h"
#include "InfinityVoid/Data/E_DeviceType.h"
#include "InfinityVoid/Utils/ZEZUtils.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AIVPlayerController::AIVPlayerController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AIVPlayerController::S_UpdateUserName_Implementation(const FString& Username)
{
	if(AIVPlayerState* PS = GetPlayerState<AIVPlayerState>())
	{
		PS->Username = Username;
	}
}

void AIVPlayerController::SetLocomotionJoystickVisibility_Implementation(bool bVisibility)
{
	if(ZEZUtils::IsValid((UObject*)MobileTouchInterface, "Mobile touch interface not defined", this) &&
		GGI->CurrentDeviceType == E_DeviceType::E_Mobile)
	{
		ActivateTouchInterface(bVisibility ? MobileTouchInterface : nullptr);
	}

}

void AIVPlayerController::TouchPressed(ETouchIndex::Type Arg, FVector Location)
{
	bTouchPressed = true;
	TouchStart = Location;
}

void AIVPlayerController::TouchReleased(ETouchIndex::Type Arg, FVector Location)
{
	bTouchPressed = false;
	TouchStart = Location;
}

// Called when the game starts or when spawned
void AIVPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	/*InputComponent = NewObject<UInputComponent>(this);
	InputComponent->RegisterComponent();
	InputComponent->BindTouch(IE_Pressed, this, &AIVPlayerController::TouchPressed);
	InputComponent->BindTouch(IE_Released, this, &AIVPlayerController::TouchReleased);*/
}

void AIVPlayerController::Tick(float DeltaSeconds)
{
	if(bTouchPressed)
	{
		float xPos, yPos;
		bool Ispressed;
		GetInputTouchState(ETouchIndex::Touch1, xPos, yPos, Ispressed);
		if(Ispressed)
			UpdateTouch(FVector(xPos, yPos, 0));
	}
	Super::Tick(DeltaSeconds);
}

void AIVPlayerController::UpdateTouch(FVector Location)
{
	FVector NetMovemeent = Location - TouchStart;
	ZEZUtils::DM("moving" + FString::SanitizeFloat(NetMovemeent.X), this);
	APawn* ControlledPawn = GetPawn();
	if(Cast<AIVCharacterBase>(ControlledPawn))
		ZEZUtils::DM("controlled pawn" , this);
	else
	{
		ZEZUtils::DM("controleld ended" , this);
	}		
	ControlledPawn->AddControllerYawInput(NetMovemeent.X/AxisSensitivity);
	ControlledPawn->AddControllerPitchInput(NetMovemeent.Y/AxisSensitivity);
}

