// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "PlayerData.h"
#include "UFriendListInterface.generated.h"


DECLARE_MULTICAST_DELEGATE_OneParam(FOnFriendUpdated, const FPlayerData&);

UCLASS(BlueprintType, Blueprintable)
class UMGTEST_API UFriendListSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual TArray<FPlayerData> GetFriendList() const;

	FOnFriendUpdated OnFriendUpdate;
};
