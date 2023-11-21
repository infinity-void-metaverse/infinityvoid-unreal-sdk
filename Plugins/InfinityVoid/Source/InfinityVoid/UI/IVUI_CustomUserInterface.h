// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IVUI_Base.h"
#include "IVUI_CustomUserInterface.generated.h"

class UCanvasPanel;
/**
 * If Player wants to use its own UserWidget then he can create child of this class and have to specify that class in HUD 
 */
UCLASS()
class INFINITYVOID_API UIVUI_CustomUserInterface : public UIVUI_Base
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UCanvasPanel* CP_Main;
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UCanvasPanel* CP_UserContainer;
	
public:
	void SetCustomPanelVisibility(bool bVisible);

protected:
	virtual void NativeOnInitialized() override;
};
