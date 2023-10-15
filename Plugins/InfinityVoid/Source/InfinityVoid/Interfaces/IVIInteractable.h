// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IVIInteractable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UIVIInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INFINITYVOID_API IIVIInteractable
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintNativeEvent)
	void OnInteraction();
};
