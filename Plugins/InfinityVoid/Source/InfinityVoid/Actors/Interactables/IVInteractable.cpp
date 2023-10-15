// Fill out your copyright notice in the Description page of Project Settings.


#include "IVInteractable.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"
#include "InfinityVoid/Core/IVCharacterBase.h"
#include "InfinityVoid/Utils/ZEZUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"


AIVInteractable::AIVInteractable()
{
	PrimaryActorTick.bCanEverTick = true;
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootScene->SetupAttachment(RootComponent);
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	VisualMesh->SetupAttachment(RootScene);
	VisualMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	VisualMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	VisualMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	VisualMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
}

void AIVInteractable::OnHoverTimerOver()
{
	DisableInput(GPC);
	//InteractWiget->SetVisibility(false);	
}

void AIVInteractable::OnHover()
{
	EnableInput(GPC);
}

void AIVInteractable::OnHoverOver()
{
	/*if(InteractWiget)
		InteractWiget->SetVisibility(false);*/
	DisableInput(GPC);
}

void AIVInteractable::PostInteract()
{
	/*if(InteractWiget)
		InteractWiget->SetVisibility(false, true);*/
	if(AIVCharacterBase* CharacterBase = Cast<AIVCharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)))
	{
		CharacterBase->ResetInteraction();
	}
}

void AIVInteractable::OnInteractPressed_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "On interaction pressed Interactable base C++");

}

void AIVInteractable::BeginPlay()
{
	Super::BeginPlay();
	InputComponent = NewObject<UInputComponent>(this);
	InputComponent->RegisterComponent();
	if(UGameplayStatics::GetPlayerController(GetWorld(),0) && bInteractable)
	{
		UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = GPC->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
		if (EnhancedInputSubsystem)
		EnhancedInputSubsystem->AddMappingContext(IMC_Interact, 1);
	}
}

void AIVInteractable::NFTTimerTick()
{
	/*NFTMintTimeRemaining -= 1;

	GDM("Time Remaining "+FString::FromInt(NFTMintTimeRemaining), this);

	if(NFTMintTimeRemaining<=0)
	{
		bNFTSet = false;
		NFTMintTimeRemaining = NFTMintTimeDurationConst;
		GDM("Remove the timer text", this);
		GetWorldTimerManager().ClearTimer(NftMintTimerHandle);
		SetOwner(nullptr);
	}*/
}

void AIVInteractable::S_OnNFTMinTInit_Implementation()
{
	/*if(!bNFTSet)
	{
		GDM("NFT Mint Initialized, Timer started for "+ FString::SanitizeFloat(NFTMintTimeDurationConst), this);
		bNFTSet = true;
		GetWorld()->GetTimerManager().SetTimer(NftMintTimerHandle, this, &AIVInteractable::NFTTimerTick, 1, true, -1);
	}*/
}

void AIVInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AIVInteractable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	/*DOREPLIFETIME(AIVInteractable, bNFTSet);
	DOREPLIFETIME(AIVInteractable, NFTMintTimeRemaining);*/
}

/*void AIVInteractable::OnNFTTimeRemainingChanged()
{
	int seconds = NFTMintTimeRemaining;
	int minutes = seconds / 60;
	int hours = minutes / 60;
	FString OutText = FString::FromInt(hours)+" : "+FString::FromInt(minutes)+" : "+FString::FromInt(seconds);
	GDM(OutText, this);
}*/

void AIVInteractable::OnInteraction_Implementation()
{
	if(bInteractable)
	{
		IIVIInteractable::OnInteraction_Implementation();
		OnInteractPressed();
	}
}


