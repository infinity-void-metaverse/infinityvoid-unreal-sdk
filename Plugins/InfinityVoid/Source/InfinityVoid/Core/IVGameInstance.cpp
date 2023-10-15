// Fill out your copyright notice in the Description page of Project Settings.


#include "IVGameInstance.h"

#include "IVCharacterBase.h"
#include "IVHUD.h"
#include "IVPlayerController.h"
#include "InfinityVoid/Utils/ZEZUtils.h"
#include "Kismet/GameplayStatics.h"


UIVGameInstance::UIVGameInstance()
{
}

void UIVGameInstance::UpdateAvatarModelURL(FString AvatarURL)
{
	UserDetail.AvatarModelURL = AvatarURL;
	if(GPS::GetPlayerCharacter(GetWorld(), 0))
	{
		AIVCharacterBase* PlayerChar = Cast<AIVCharacterBase>(GPS::GetPlayerCharacter(GetWorld(), 0));
		if(PlayerChar)
		{
			PlayerChar->S_UpdateUserDetail(UserDetail);
		}
	}
}

void UIVGameInstance::UpdateAvatarUsername(FString _AvatarUserName)
{
	UserDetail.UserName = _AvatarUserName;
	if(GPS::GetPlayerCharacter(GetWorld(), 0))
	{
		AIVCharacterBase* PlayerChar = Cast<AIVCharacterBase>(GPS::GetPlayerCharacter(GetWorld(), 0));
		if(PlayerChar)
		{
			PlayerChar->S_UpdateUserDetail(UserDetail);
		}
	}
}

void UIVGameInstance::SetDeviceType(E_DeviceType _CurrentDeviceType)
{
	CurrentDeviceType = _CurrentDeviceType;
	if(CurrentDeviceType == E_DeviceType::E_Mobile && GPC)
	{
		if(AIVHUD* HUDObj = Cast<AIVHUD>(GPC->GetHUD()))
		{
			HUDObj->SetJoystickButtonsVisibility(true);				
		}
		if(GPS::GetPlayerCharacter(GetWorld(), 0))
		{
			AIVCharacterBase* PlayerChar = Cast<AIVCharacterBase>(GPS::GetPlayerCharacter(GetWorld(), 0));
			if(PlayerChar)
			{
				PlayerChar->OnSprintStart();
			}
		}
		Cast<AIVPlayerController>(GPC)->SetLocomotionJoystickVisibility(true); 
	}
}

void UIVGameInstance::Init()
{
	Super::Init();
	
}

void UIVGameInstance::LoadComplete(const float LoadTime, const FString& MapName)
{
	Super::LoadComplete(LoadTime, MapName);
	ZEZUtils::DM("LoadComplete from GI", GPP);
}
