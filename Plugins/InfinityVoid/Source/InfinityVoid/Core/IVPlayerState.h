// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "IVPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYVOID_API AIVPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnUsernameUpdated) FString Username;
public:
	AIVPlayerState();

protected:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION() void OnUsernameUpdated();
};
