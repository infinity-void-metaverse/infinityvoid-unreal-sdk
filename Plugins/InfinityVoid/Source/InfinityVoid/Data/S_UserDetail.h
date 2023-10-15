// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "S_UserDetail.generated.h"

// This class does not need to be modified.
USTRUCT(BlueprintType)
struct FS_UserDetail : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString UserID {""};
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString UserName {""};
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString AvatarModelURL {""};
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString WalletAddress {""};
};
