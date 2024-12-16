// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerData.generated.h"

USTRUCT(BlueprintType)
struct UMGTEST_API FPlayerData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString PlayerNickname;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 PlayerLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bStatus;

};
