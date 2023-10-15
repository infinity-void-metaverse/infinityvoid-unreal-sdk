// Fill out your copyright notice in the Description page of Project Settings.


#include "IVGLTFActorAsync.h"



void AIVGLTFActorAsync::OnInteraction_Implementation()
{
	IIVIInteractable::OnInteraction_Implementation();
	OnInteract();
}

