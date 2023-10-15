// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "..\..\Interfaces\IVIInteractable.h"
#include "InputMappingContext.h"
#include "IVInteractable.generated.h"

UCLASS()
class INFINITYVOID_API AIVInteractable : public AActor, public IIVIInteractable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere) USceneComponent* RootScene;
	UPROPERTY(EditAnywhere) UInputMappingContext* IMC_Interact;
	UPROPERTY(EditAnywhere) UInputAction* IA_Interact;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UStaticMeshComponent* VisualMesh;
	UPROPERTY(EditAnywhere) int HoverTimerWait = 5;
	UPROPERTY(EditAnywhere) FString HUDInteractionText = "Interact";
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bInteractable {true};
/*	UPROPERTY(EditAnywhere) int NFTMintTimeDurationConst {(int)(.5*60*60)};	//In Seconds - hh*mm*ss
	UPROPERTY(EditAnywhere, ReplicatedUsing = OnNFTTimeRemainingChanged) int NFTMintTimeRemaining {NFTMintTimeDurationConst};	//In Seconds - hh*mm*ss
	UPROPERTY(BlueprintReadWrite, Replicated) bool bNFTSet {false};
*/
public:
	AIVInteractable();
	void OnHover();
	void OnHoverOver();
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintNativeEvent)	void OnInteractPressed();
	UFUNCTION(BlueprintCallable) void PostInteract();
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	//UFUNCTION() void OnNFTTimeRemainingChanged();
	virtual void OnInteraction_Implementation() override;

protected:
	void OnHoverTimerOver();
	virtual void BeginPlay() override;
	UFUNCTION(Server, Reliable, BlueprintCallable) virtual void S_OnNFTMinTInit();
	
private:
	FTimerHandle NftMintTimerHandle;
	//UUserWidget* UWInteraction;
	
	private:
	UFUNCTION() void NFTTimerTick();
};
