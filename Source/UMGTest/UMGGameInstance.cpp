// Fill out your copyright notice in the Description page of Project Settings.


#include "UMGGameInstance.h"

#include "UFrindLIstMock.h"

void UUMGGameInstance::Init()
{
	Super::Init();

	// Get the subsystem
	UFriendListSubsystem* Subsystem = GetSubsystem<UMockList>();
	if (Subsystem) {
		// register events with handlers
		Subsystem->OnFriendUpdate.AddUObject(this, &UUMGGameInstance::OnFriendListUpdated);
	}

}

TArray<FPlayerData> UUMGGameInstance::GetFriendList() const
{
	// Get the subsystem
	UFriendListSubsystem* Subsystem = GetSubsystem<UMockList>();
	if (Subsystem) {
		return Subsystem->GetFriendList();
	}
	return TArray<FPlayerData>();
}

void UUMGGameInstance::OnFriendListUpdated(const FPlayerData& PlayerData)
{
	OnConnectionEvent.Broadcast(PlayerData);
}
