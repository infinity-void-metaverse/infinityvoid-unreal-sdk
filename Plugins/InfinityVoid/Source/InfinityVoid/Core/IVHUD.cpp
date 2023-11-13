// Fill out your copyright notice in the Description page of Project Settings.


#include "IVHUD.h"

#include "IVGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "InfinityVoid/UI/IVUI_CustomUserInterface.h"
#include "InfinityVoid/UI/IVUI_Main.h"
#include "InfinityVoid/Utils/ZEZUtils.h"
#include "Kismet/GameplayStatics.h"


AIVHUD::AIVHUD()
{
}

void AIVHUD::UpdateCrosshair(bool IsInteractable)
{
	if(MainUIObj)
		MainUIObj->UpdateCrosshairTexture(IsInteractable);
}

void AIVHUD::SetCrosshairVisibility(bool bVisible)
{
	if(MainUIObj)
		MainUIObj->SetCrosshairVisibility(bVisible);
}

void AIVHUD::SetJumpButtonVisibility(bool bVisible)
{
	if(MainUIObj)
		MainUIObj->SetJumpButtonVisibility(bVisible);
}

void AIVHUD::SetInteractButtonVisibility(bool bVisible)
{
	if(MainUIObj)
		MainUIObj->SetInteractVisibility(bVisible);
}

void AIVHUD::SetJoystickButtonsVisibility(bool bVisible)
{
	if(MainUIObj)
		MainUIObj->SetJoystickVisibility(bVisible);
	SetCustomUserWidgetVisibility(true);
}

void AIVHUD::SetCustomUserWidgetVisibility(bool bVisible)
{
	if(CustomeUserInterfaceUIObj)
		CustomeUserInterfaceUIObj->SetCustomPanelVisibility(bVisible);
}

void AIVHUD::SetVehicleInteractionButtonVisibility(bool bVisible)
{
	if(MainUIObj)
		MainUIObj->SetCarInteractionButtonVisibility(bVisible);
}

void AIVHUD::UpdateInteractionText(FString TextValue) const
{
	if(MainUIObj)
		MainUIObj->UpdateInfoText(TextValue);
}

void AIVHUD::BeginPlay()
{
	Super::BeginPlay();
}

void AIVHUD::AddCrosshairMainScreen()
{
	if(ZEZUtils::IsValid(MainUIClass, "Main UI Class not defined", this))
	{
		MainUIObj = CreateWidget<UIVUI_Main>(GetOwningPlayerController(), MainUIClass);
		MainUIObj->AddToViewport();
		if(GGI->CurrentDeviceType==E_DeviceType::E_Mobile)
			SetJoystickButtonsVisibility(true);
	}
	
	if(ZEZUtils::IsValid(CustomUserInterfaceUIClass, "CustomUserInterfaceUIClass Class not defined", this))
	{
		CustomeUserInterfaceUIObj = CreateWidget<UIVUI_CustomUserInterface>(GetOwningPlayerController(), CustomUserInterfaceUIClass);
		CustomeUserInterfaceUIObj->AddToViewport();
		if(GGI->CurrentDeviceType==E_DeviceType::E_Mobile)
			SetCustomUserWidgetVisibility(true);
	}
}

void AIVHUD::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

