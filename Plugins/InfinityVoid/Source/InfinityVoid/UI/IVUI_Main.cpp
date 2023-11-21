// Fill out your copyright notice in the Description page of Project Settings.


#include "IVUI_Main.h"

#include "InputActionValue.h"
#include "InfinityVoid/Core/IVCharacterBase.h"
#include "InfinityVoid/Utils/ZEZUtils.h"
#include "Kismet/GameplayStatics.h"


void UIVUI_Main::UpdateCrosshairTexture(bool IsInteractable)
{
	UTexture2D* finalTexture = IsInteractable ? I_CrosshairInteract : I_CrosshairWithoutInteract;
	if(finalTexture)	
		I_InteractCrosshair->SetBrushFromTexture(finalTexture);
	else
		ZEZUtils::DM("texture not set in UIMain", GetOwningPlayer());
}

void UIVUI_Main::SetCrosshairVisibility(bool bVisible) 
{
	SetWidgetVisibility(bVisible, CP_Crosshair);
}

void UIVUI_Main::SetJumpButtonVisibility(bool bVisible) 
{
	SetWidgetVisibility(bVisible, B_Jump);
}

void UIVUI_Main::SetInteractVisibility(bool bVisible) 
{
	SetWidgetVisibility(bVisible, B_Interact);
	SetWidgetVisibility(bVisible, CP_InteractIcon);
}

void UIVUI_Main::SetJoystickVisibility(bool bVisible)
{
	SetWidgetVisibility(bVisible, CP_JoystickButtons);
}

void UIVUI_Main::SetCarInteractionButtonVisibility(bool bVisible)
{
	SetWidgetVisibility(bVisible, B_CarInteraction);
}

void UIVUI_Main::UpdateInfoText(FString Message)
{
	if(TB_Info && !Message.IsEmpty())
		TB_Info->SetText(FText::FromString(Message));
}

void UIVUI_Main::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	B_Jump->SetVisibility(ESlateVisibility::Collapsed);
	CP_JoystickButtons->SetVisibility(ESlateVisibility::Collapsed);
	B_CarInteraction->SetVisibility(ESlateVisibility::Collapsed);
	B_Interact->SetVisibility(ESlateVisibility::Collapsed);
	CP_InteractIcon->SetVisibility(ESlateVisibility::Collapsed);
}			

void UIVUI_Main::NativeConstruct()
{
	Super::NativeConstruct();
	
	B_Jump->OnPressed.AddDynamic(this, &UIVUI_Main::OnJumpPressed);
	B_Interact->OnPressed.AddDynamic(this, &UIVUI_Main::OnInteractPressed);
}

AIVCharacterBase* UIVUI_Main::GetPlayerChar()
{
	if(!PlayerChar)
		PlayerChar = Cast<AIVCharacterBase>(GPChar);
	return PlayerChar;
}


void UIVUI_Main::OnJumpPressed()
{
	if(ZEZUtils::IsValid(GetPlayerChar(), "Player Character is not valid ",GetOwningPlayer()))
		PlayerChar->Jump();
}

void UIVUI_Main::OnInteractPressed()
{
	ZEZUtils::DM("On interac pressed", GetOwningPlayer());
	if(ZEZUtils::IsValid(GetPlayerChar(), "Player Character is not valid ",GetOwningPlayer()))
		PlayerChar->OnInteractPressed(FInputActionValue()); //TODO @Mayank we are replacing with default value
}

