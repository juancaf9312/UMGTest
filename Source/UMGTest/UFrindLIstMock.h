// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UFriendListInterface.h"
#include "UFrindLIstMock.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class UMGTEST_API UMockList : public UFriendListSubsystem
{
	GENERATED_BODY()

	TArray<FPlayerData> FriendList;

	void UpdateRandomFriend();

public:
	UMockList();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	virtual TArray<FPlayerData> GetFriendList() const override { return FriendList; }
	
};
