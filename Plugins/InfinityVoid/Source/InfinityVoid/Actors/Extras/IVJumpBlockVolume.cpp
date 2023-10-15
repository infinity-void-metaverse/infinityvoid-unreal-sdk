// Fill out your copyright notice in the Description page of Project Settings.


#include "IVJumpBlockVolume.h"

#include "GameFramework/Character.h"
#include "InfinityVoid/Core/IVCharacterBase.h"
#include "InfinityVoid/Core/IVHUD.h"
#include "InfinityVoid/Utils/ZEZUtils.h"
#include "Kismet/GameplayStatics.h"

void AIVJumpBlockVolume::OnJumpBlockColliderBeginOverlapped(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
                                                             UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult)
{
	TurnJumpOnForChar(Actor);
}

void AIVJumpBlockVolume::TurnJumpOnForChar(AActor* Actor)
{
	ZEZUtils::DM("TurnJupm on CHaracter on beginoverlap", this);
	if(AIVCharacterBase* GameCharacter = Cast<AIVCharacterBase>(Actor))
	{
		if(GameCharacter->IsLocallyControlled())
		{
			GameCharacter->bJumpAllowed = true;
			if(AIVHUD* HUDObj = Cast<AIVHUD>(GPC->GetHUD()))
			{
				HUDObj->SetJumpButtonVisibility(true);
			}
		}
	}
}

void AIVJumpBlockVolume::OnJumpBlockColliderEndOverlapped(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
	UPrimitiveComponent* PrimitiveComponent1, int I)
{
	if(AIVCharacterBase* GameCharacter = Cast<AIVCharacterBase>(Actor))
	{
		if(GameCharacter->IsLocallyControlled())
		{
			GameCharacter->bJumpAllowed = false;
			if(AIVHUD* HUDObj = Cast<AIVHUD>(GPC->GetHUD()))
			{
				HUDObj->SetJumpButtonVisibility(false);				
			}
		}
	}
}

AIVJumpBlockVolume::AIVJumpBlockVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	JumpBlockBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("JumpBlockBoxCollision"));
	JumpBlockBoxCollision->SetupAttachment(RootComponent);
	JumpBlockBoxCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	JumpBlockBoxCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}

void AIVJumpBlockVolume::BeginPlay()
{
	Super::BeginPlay();
	JumpBlockBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AIVJumpBlockVolume::OnJumpBlockColliderBeginOverlapped);
	JumpBlockBoxCollision->OnComponentEndOverlap.AddDynamic(this, &AIVJumpBlockVolume::OnJumpBlockColliderEndOverlapped);
	OnPlayerCollisionChanged();
}

void AIVJumpBlockVolume::OnPlayerCollisionChanged()
{
	if(GPChar)
	{
		const FVector VectorToPlayer = GPChar->GetActorLocation() - JumpBlockBoxCollision->GetComponentLocation();
		const FVector Extend = JumpBlockBoxCollision->GetScaledBoxExtent();

		if(VectorToPlayer.X <= Extend.X && VectorToPlayer.Y <= Extend.Y && VectorToPlayer.Z <= Extend.Z )
		{
			TurnJumpOnForChar(GPChar);
		}		
	}
}

void AIVJumpBlockVolume::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	FTimerHandle someTimerHandle;
	GetWorldTimerManager().SetTimer(someTimerHandle, FTimerDelegate::CreateLambda([&]()
	{
		if(AIVCharacterBase* Charbase = Cast<AIVCharacterBase>(GPChar))
		{
			Charbase->OnCollisionChanged.AddDynamic(this, &AIVJumpBlockVolume::OnPlayerCollisionChanged);
		}
	}), 1, false, 5);

}

// Called every frame
void AIVJumpBlockVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

