// Fill out your copyright notice in the Description page of Project Settings.


#include "IVUI_Base.h"

#include "Components/Button.h"


void UIVUI_Base::SetWidgetVisibility(bool bVisible, UWidget* TargetWidget)
{
	if(TargetWidget)
	{
		TargetWidget->SetVisibility(bVisible ?
			(Cast<UButton>(TargetWidget) ? ESlateVisibility::Visible : ESlateVisibility::SelfHitTestInvisible)
			: ESlateVisibility::Collapsed);
	}
}
