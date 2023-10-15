// Fill out your copyright notice in the Description page of Project Settings.


#include "ZEZSpawner.h"

#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "InfinityVoid/Utils/ZEZUtils.h"


// Sets default values
AZEZSpawner::AZEZSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USphereComponent>(TEXT("Root"));
	RootComponent = Root;
	SpawnerRangeSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SpawnerRangeSphere"));
	SpawnerRangeSphere->SetupAttachment(Root);
	SM_VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_VisualMesh"));
	SM_VisualMesh->SetupAttachment(Root);
}

void AZEZSpawner::SpawnerRangeSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(ACharacter* Char = Cast<ACharacter>(OtherActor))
	{
		if(ClassToSpawn && !bSpawned)
		{
			bSpawned = true;
			GetWorld()->SpawnActor<AActor>(ClassToSpawn, GetActorLocation(), GetActorRotation());
			Destroy();
		}
		else
		{
			ZEZUtils::DM("Class to spawn not defined", this);
		}
	}
}

// Called when the game starts or when spawned
void AZEZSpawner::BeginPlay()
{
	Super::BeginPlay();
	if(HasAuthority())
	{
		SpawnerRangeSphere->OnComponentBeginOverlap.AddDynamic(this, &AZEZSpawner::SpawnerRangeSphereOverlapBegin);
	}
}

// Called every frame
void AZEZSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

