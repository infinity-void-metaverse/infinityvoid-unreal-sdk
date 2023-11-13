// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "IVHUD.generated.h"

class UIVUI_CustomUserInterface;
class UIVUI_Interaction;
class UIVUI_Main;
/**
 * 
 */
UCLASS()
class INFINITYVOID_API AIVHUD : public AHUD
{
	GENERATED_BODY()

	
public:
	UPROPERTY(EditAnywhere) TSubclassOf<UIVUI_Main> MainUIClass;
	UPROPERTY(EditAnywhere) TSubclassOf<UIVUI_CustomUserInterface> CustomUserInterfaceUIClass;
	
public:
	AIVHUD();
	void UpdateCrosshair(bool IsInteractable);
	void UpdateInteractionText(FString TextValue) const;
	UFUNCTION(BlueprintCallable) void SetCrosshairVisibility(bool bVisible);
	UFUNCTION(BlueprintCallable) void SetJumpButtonVisibility(bool bVisible);
	UFUNCTION(BlueprintCallable) void SetInteractButtonVisibility(bool bVisible);
	UFUNCTION(BlueprintCallable) void SetJoystickButtonsVisibility(bool bVisible);
	UFUNCTION(BlueprintCallable) void SetCustomUserWidgetVisibility(bool bVisible);
	UFUNCTION(BlueprintCallable) void SetVehicleInteractionButtonVisibility(bool bVisible);

private:
	UIVUI_Main* MainUIObj;
	UIVUI_CustomUserInterface* CustomeUserInterfaceUIObj;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable) void AddCrosshairMainScreen();

};
