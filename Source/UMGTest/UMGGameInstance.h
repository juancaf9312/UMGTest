// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UMGGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FConnectionEvent, const FPlayerData&, Player);

/**
 * 
 */
UCLASS()
class UMGTEST_API UUMGGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init() override;

	TArray<struct FPlayerData> GetFriendList() const;

	void OnFriendListUpdated(const struct FPlayerData& PlayerData);

	FConnectionEvent OnConnectionEvent;
};
