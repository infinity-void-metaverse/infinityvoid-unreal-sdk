// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "E_DeviceType.generated.h"

UENUM(BlueprintType)
enum class E_DeviceType: uint8
{
	E_Windows		UMETA(DisplayName = "Windows"),
	E_Mobile		UMETA(DisplayName = "Mobile"),
	Count		UMETA(Hidden)
};