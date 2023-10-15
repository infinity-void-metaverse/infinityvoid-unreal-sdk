#include "ZEZCharacterMovementComponent.h"
#include "GameFramework/Character.h"

void UZEZCharacterMovementComponent::FSavedMoved_ZEZ::SetMoveFor(ACharacter* C, float InDeltaTime, FVector const& NewAccel,
                                                        FNetworkPredictionData_Client_Character& ClientData)
{
	FSavedMove_Character::SetMoveFor(C, InDeltaTime, NewAccel, ClientData);
	UZEZCharacterMovementComponent* ZEZCharacterMovementComponent = Cast<UZEZCharacterMovementComponent>(C->GetCharacterMovement());
	Saved_bWantsToSprint = ZEZCharacterMovementComponent->safe_bWantsToSprint;
	
}

bool UZEZCharacterMovementComponent::FSavedMoved_ZEZ::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* InCharacter,
	float MaxDelta) const
{
	FSavedMoved_ZEZ* ZEZMoveSaved = static_cast<FSavedMoved_ZEZ*>(NewMove.Get());
	if(ZEZMoveSaved->Saved_bWantsToSprint != Saved_bWantsToSprint)
	{
		return false;
	}
	return FSavedMove_Character::CanCombineWith(NewMove, InCharacter, MaxDelta); 
}

void UZEZCharacterMovementComponent::FSavedMoved_ZEZ::CombineWith(const FSavedMove_Character* OldMove, ACharacter* InCharacter,
	APlayerController* PC, const FVector& OldStartLocation)
{
	FSavedMove_Character::CombineWith(OldMove, InCharacter, PC, OldStartLocation);
}

void UZEZCharacterMovementComponent::FSavedMoved_ZEZ::PrepMoveFor(ACharacter* C)
{
	FSavedMove_Character::PrepMoveFor(C);
	
	UZEZCharacterMovementComponent* ZEZCharacterMovementComponent = Cast<UZEZCharacterMovementComponent>(C->GetCharacterMovement());
	ZEZCharacterMovementComponent->safe_bWantsToSprint = Saved_bWantsToSprint;
}

uint8 UZEZCharacterMovementComponent::FSavedMoved_ZEZ::GetCompressedFlags() const
{
	uint8 Result = FSavedMove_Character::GetCompressedFlags();
	if(Saved_bWantsToSprint)
		Result |= FLAG_Custom_0;
	return Result;
}

void UZEZCharacterMovementComponent::FSavedMoved_ZEZ::Clear()
{
	FSavedMove_Character::Clear();
	Saved_bWantsToSprint = false;
}

UZEZCharacterMovementComponent::FNetworkPredictionData_Client_ZEZ::FNetworkPredictionData_Client_ZEZ(
	const UCharacterMovementComponent& ClientMovement): Super(ClientMovement)
{
}

FSavedMovePtr UZEZCharacterMovementComponent::FNetworkPredictionData_Client_ZEZ::AllocateNewMove()
{
	return FSavedMovePtr(new FSavedMoved_ZEZ());
}

FNetworkPredictionData_Client* UZEZCharacterMovementComponent::GetPredictionData_Client() const
{
	check(PawnOwner != nullptr)

	if(ClientPredictionData == nullptr)
	{
		UZEZCharacterMovementComponent* CMC = const_cast<UZEZCharacterMovementComponent*>(this);
		CMC->ClientPredictionData = new FNetworkPredictionData_Client_ZEZ(*this);
		CMC->ClientPredictionData->MaxSmoothNetUpdateDist = 92.f;
		CMC->ClientPredictionData->NoSmoothNetUpdateDist = 140.f;
	}
	return ClientPredictionData;
}

void UZEZCharacterMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
	Super::UpdateFromCompressedFlags(Flags);
	safe_bWantsToSprint = (Flags & FSavedMove_Character::FLAG_Custom_0) != 0;
}

void UZEZCharacterMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation,
	const FVector& OldVelocity)
{
	Super::OnMovementUpdated(DeltaSeconds, OldLocation, OldVelocity);
	if(MovementMode == MOVE_Walking)
	{
		if(safe_bWantsToSprint)
		{
			MaxWalkSpeed = Sprint_MaxWalkSpeed;
		}
		else
		{
			MaxWalkSpeed = Walk_MaxWalkSpeed;
		}
	}
	
}

void UZEZCharacterMovementComponent::SprintPressed()
{
	safe_bWantsToSprint = true;
}

void UZEZCharacterMovementComponent::SprintReleased()
{
	safe_bWantsToSprint = false;
}
