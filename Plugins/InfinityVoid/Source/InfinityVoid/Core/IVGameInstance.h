// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "InfinityVoid/Data/E_DeviceType.h"
#include "InfinityVoid/Data/S_UserDetail.h"
#include "IVGameInstance.generated.h"

UCLASS()
class INFINITYVOID_API UIVGameInstance : public UGameInstance
{
	GENERATED_BODY()

	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FVector CharacterSavedLoc {FVector::ZeroVector};
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FRotator CharacterSavedRot {FRotator::ZeroRotator};
	UPROPERTY(BlueprintReadWrite, EditAnywhere) E_DeviceType CurrentDeviceType = E_DeviceType::E_Windows;
	
public:
	UIVGameInstance();
	UFUNCTION(BlueprintImplementableEvent) void TurnEnvLightOnOff(bool bLightVisibility);
	UFUNCTION(BlueprintCallable) void UpdateAvatarModelURL(FString AvatarURL);
	UFUNCTION(BlueprintCallable) void UpdateAvatarUsername(FString _AvatarUserName);
	UFUNCTION(BlueprintCallable) void SetDeviceType(E_DeviceType _CurrentDeviceType);
	UFUNCTION(BlueprintCallable) void UpdateUserDetail(FS_UserDetail _UserDetail) {UserDetail = _UserDetail;};
	UFUNCTION(BlueprintCallable) FS_UserDetail GetUserDetail() {return UserDetail;}
	
protected:
	virtual void Init() override;
	virtual void LoadComplete(const float LoadTime, const FString& MapName) override;

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true)) FS_UserDetail UserDetail;

};
