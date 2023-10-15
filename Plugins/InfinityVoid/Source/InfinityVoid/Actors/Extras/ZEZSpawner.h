// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ZEZSpawner.generated.h"

UCLASS()
class INFINITYVOID_API AZEZSpawner : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) class USceneComponent* Root;
	UPROPERTY(EditAnywhere) class USphereComponent* SpawnerRangeSphere;
	UPROPERTY(EditAnywhere) class UStaticMeshComponent* SM_VisualMesh;

	UPROPERTY(EditAnywhere) TSubclassOf<AActor> ClassToSpawn;
	virtual void Tick(float DeltaTime) override;
	
public:
	AZEZSpawner();

protected:
	UFUNCTION()
	void SpawnerRangeSphereOverlapBegin( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	virtual void BeginPlay() override;

private:
	bool bSpawned = false;
};
