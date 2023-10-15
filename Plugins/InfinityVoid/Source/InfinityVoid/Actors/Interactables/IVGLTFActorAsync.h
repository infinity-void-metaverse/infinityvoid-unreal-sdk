// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "glTFRuntimeAssetActorAsync.h"
#include "..\..\Interfaces\IVIInteractable.h"
#include "IVGLTFActorAsync.generated.h"

UCLASS()
class INFINITYVOID_API AIVGLTFActorAsync : public AglTFRuntimeAssetActorAsync, public IIVIInteractable
{
	GENERATED_BODY()

public:	
	virtual void OnInteraction_Implementation() override;
	UFUNCTION(BlueprintImplementableEvent) void OnInteract();
};
