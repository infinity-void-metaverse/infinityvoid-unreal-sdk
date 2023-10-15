// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "IVPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYVOID_API AIVPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	UPROPERTY(EditAnywhere) float AxisSensitivity = 5;
	UPROPERTY(EditAnywhere) UTouchInterface* MobileTouchInterface;
	
public:
	AIVPlayerController();
	UFUNCTION(Server, Reliable, BlueprintCallable) void S_UpdateUserName(const FString& Username);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent) void SetLocomotionJoystickVisibility(bool bVisibility);
	void TouchPressed(ETouchIndex::Type Arg, FVector Location);
	void TouchReleased(ETouchIndex::Type Arg,FVector Location);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

private:
	bool bTouchPressed = false;
	FVector TouchStart = FVector::ZeroVector;
	void UpdateTouch(FVector Location);
};
