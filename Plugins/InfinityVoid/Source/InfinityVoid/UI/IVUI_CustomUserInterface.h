// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IVUI_CustomUserInterface.generated.h"

class UCanvasPanel;
/**
 * If Player wants to use its own UserWidget then he can create child of this class and have to specify that class in HUD 
 */
UCLASS()
class INFINITYVOID_API UIVUI_CustomUserInterface : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UCanvasPanel* CP_Main;
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UCanvasPanel* CP_UserContainer;
	
public:
	void SetCustomPanelVisibility(bool bVisible);
	void SetWidgetVisibility(bool bVisible, UWidget* TargetWidget);

protected:
	virtual void NativeOnInitialized() override;
};
