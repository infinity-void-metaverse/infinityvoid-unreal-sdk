// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "IVJumpBlockVolume.generated.h"

UCLASS()
class INFINITYVOID_API AIVJumpBlockVolume : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UBoxComponent* JumpBlockBoxCollision;
	//UPROPERTY(EditAnywhere) UStaticMeshComponent* VisualBox;
	
public:
	UFUNCTION()
	void OnJumpBlockColliderBeginOverlapped(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I, bool bArg,
	                                        const FHitResult& HitResult);
	void TurnJumpOnForChar(AActor* Actor);
	UFUNCTION()
	void OnJumpBlockColliderEndOverlapped(UPrimitiveComponent* PrimitiveComponent, AActor* Actor, UPrimitiveComponent* PrimitiveComponent1, int I);

	// Sets default values for this actor's properties
	AIVJumpBlockVolume();

protected:
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnPlayerCollisionChanged();	
	virtual void PostInitializeComponents() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
