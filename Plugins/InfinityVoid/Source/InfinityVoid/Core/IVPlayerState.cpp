// Fill out your copyright notice in the Description page of Project Settings.


#include "IVPlayerState.h"

#include "InfinityVoid/Utils/ZEZUtils.h"
#include "Net/UnrealNetwork.h"


AIVPlayerState::AIVPlayerState()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AIVPlayerState::OnUsernameUpdated()
{
	ZEZUtils::DM("Username Updated", this);
}

void AIVPlayerState::BeginPlay()
{
	Super::BeginPlay();
	
}

void AIVPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AIVPlayerState, Username)
}

