// Fill out your copyright notice in the Description page of Project Settings.


#include "IVUI_CustomUserInterface.h"

#include "Components/CanvasPanel.h"

void UIVUI_CustomUserInterface::SetCustomPanelVisibility(bool bVisible)
{
	SetWidgetVisibility(true,CP_UserContainer);
}


void UIVUI_CustomUserInterface::SetWidgetVisibility(bool bVisible, UWidget* TargetWidget)
{
	if(TargetWidget)
	{
		TargetWidget->SetVisibility(bVisible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	}
}

void UIVUI_CustomUserInterface::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	CP_UserContainer->SetVisibility(ESlateVisibility::Collapsed);
}
