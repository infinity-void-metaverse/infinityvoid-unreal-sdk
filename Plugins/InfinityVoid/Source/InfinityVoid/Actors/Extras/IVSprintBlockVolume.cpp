// Fill out your copyright notice in the Description page of Project Settings.


#include "IVSprintBlockVolume.h"

#include "InfinityVoid/Core/IVCharacterBase.h"
#include "InfinityVoid/Core/IVHUD.h"
#include "InfinityVoid/Utils/ZEZUtils.h"
#include "Kismet/GameplayStatics.h"


void AIVSprintBlockVolume::OnSprintBlockColliderBeginOverlapped(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
                                                                UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg, const FHitResult& HitResult)
{
	TurnSprintForChar(Actor);
}

void AIVSprintBlockVolume::OnSprintBlockColliderEndOverlapped(UPrimitiveComponent* PrimitiveComponent, AActor* Actor,
	UPrimitiveComponent* PrimitiveComponent1, int I)
{
	if(AIVCharacterBase* GameCharacter = Cast<AIVCharacterBase>(Actor))
	{
		GameCharacter->bSprintAllowed = true;
	}
}


void AIVSprintBlockVolume::TurnSprintForChar(AActor* Actor)
{
	if(AIVCharacterBase* GameCharacter = Cast<AIVCharacterBase>(Actor))
	{
		GameCharacter->bSprintAllowed = false;
	}
}

void AIVSprintBlockVolume::OnPlayerCollisionChanged()
{
	if(GPChar)
	{
		const FVector VectorToPlayer = GPChar->GetActorLocation() - JumpBlockBoxCollision->GetComponentLocation();
		const FVector Extend = JumpBlockBoxCollision->GetScaledBoxExtent();

		if(VectorToPlayer.X <= Extend.X && VectorToPlayer.Y <= Extend.Y && VectorToPlayer.Z <= Extend.Z )
		{
			TurnSprintForChar(GPChar);
		}
	}
}

AIVSprintBlockVolume::AIVSprintBlockVolume()
{
	PrimaryActorTick.bCanEverTick = true;
	JumpBlockBoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("JumpBlockBoxCollision"));
	JumpBlockBoxCollision->SetupAttachment(RootComponent);
	JumpBlockBoxCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	JumpBlockBoxCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}


void AIVSprintBlockVolume::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	FTimerHandle someTimerHandle;
	GetWorldTimerManager().SetTimer(someTimerHandle, FTimerDelegate::CreateLambda([&]()
	{
		if(GPChar)
		if(AIVCharacterBase* Charbase = Cast<AIVCharacterBase>(GPChar))
		{
			Charbase->OnCollisionChanged.AddDynamic(this, &AIVSprintBlockVolume::OnPlayerCollisionChanged);
		}
	}), 1, false, 5);

}

void AIVSprintBlockVolume::BeginPlay()
{
	Super::BeginPlay();
	JumpBlockBoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AIVSprintBlockVolume::OnSprintBlockColliderBeginOverlapped);
	JumpBlockBoxCollision->OnComponentEndOverlap.AddDynamic(this, &AIVSprintBlockVolume::OnSprintBlockColliderEndOverlapped);
	OnPlayerCollisionChanged();
}

void AIVSprintBlockVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

