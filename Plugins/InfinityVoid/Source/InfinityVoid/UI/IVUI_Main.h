// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "IVUI_Main.generated.h"

/**
 * 
 */
UCLASS()
class INFINITYVOID_API UIVUI_Main : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UCanvasPanel* CP_Main;
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UCanvasPanel* CP_Crosshair;
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UImage* I_InteractCrosshair;
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UButton* B_Jump;
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UButton* B_CarInteraction;
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UCanvasPanel* CP_JoystickButtons;
	UPROPERTY(EditAnywhere) UTexture2D* I_CrosshairInteract;
	UPROPERTY(EditAnywhere) UTexture2D* I_CrosshairWithoutInteract;

	UPROPERTY(EditAnywhere, meta = (BindWidget)) UCanvasPanel* CP_InteractIcon;
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UImage* I_Interact;
	UPROPERTY(EditAnywhere, meta = (BindWidget)) UButton* B_Interact;
	UPROPERTY(EditAnywhere, meta = (BindWidget), BlueprintReadOnly) UTextBlock* TB_Info;

public:

	UFUNCTION()	void OnJumpPressed();
	UFUNCTION()	void OnInteractPressed();
	
	UFUNCTION(BlueprintCallable) void UpdateCrosshairTexture(bool IsInteractable);
	UFUNCTION(BlueprintCallable) void SetCrosshairVisibility(bool bVisible);
	UFUNCTION(BlueprintCallable) void SetJumpButtonVisibility(bool bVisible);
	UFUNCTION(BlueprintCallable) void SetInteractVisibility(bool bVisible);
	UFUNCTION(BlueprintCallable) void SetJoystickVisibility(bool bVisible);
	UFUNCTION(BlueprintCallable) void SetCarInteractionButtonVisibility(bool bVisible);
	UFUNCTION(BlueprintCallable) void UpdateInfoText(FString Message);

protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
	class AIVCharacterBase* GetPlayerChar();

private:
	class AIVCharacterBase* PlayerChar = nullptr;
	
private:
	void SetWidgetVisibility(bool bVisible, UWidget* TargetWidget);
};
