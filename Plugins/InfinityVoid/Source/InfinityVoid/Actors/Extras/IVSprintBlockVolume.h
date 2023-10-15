// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "IVSprintBlockVolume.generated.h"

UCLASS()
class INFINITYVOID_API AIVSprintBlockVolume : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UBoxComponent* JumpBlockBoxCollision;
	
public:
	UFUNCTION()
	void OnSprintBlockColliderBeginOverlapped(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg,
	                                        const FHitResult& HitResult);
	UFUNCTION()
	void OnSprintBlockColliderEndOverlapped(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I);
	void TurnSprintForChar(AActor* Actor);
	UFUNCTION()
	void OnPlayerCollisionChanged();	
	AIVSprintBlockVolume();
	virtual void PostInitializeComponents() override;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
