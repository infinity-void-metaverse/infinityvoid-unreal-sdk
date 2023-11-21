// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IVUI_Base.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYVOID_API UIVUI_Base : public UUserWidget
{
	GENERATED_BODY()
protected:
	static void SetWidgetVisibility(bool bVisible, UWidget* TargetWidget);
};
