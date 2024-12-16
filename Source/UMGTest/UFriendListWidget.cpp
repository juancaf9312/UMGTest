// Fill out your copyright notice in the Description page of Project Settings.


#include "UFriendListWidget.h"
#include "UMGGameInstance.h"
#include "UMGListEntry.h"
#include "PlayerData.h"
#include "EntryListData.h"
#include "Components/ListView.h"
#include "Components/TextBlock.h"

bool UUFriendListWidget::Initialize()
{
	Super::Initialize();

	UUMGGameInstance* GameInstance = GetGameInstance<UUMGGameInstance>();
	if (GameInstance) {

		// Bind the event
		GameInstance->OnConnectionEvent.AddDynamic(this, &UUFriendListWidget::onFriendUpdate);

		// Get initil player list
		TArray<FPlayerData> PlayerList = GameInstance->GetFriendList();
		for (const FPlayerData& Player : PlayerList) {
			UEntryListData* EntryData = NewObject<UEntryListData>();
			EntryData->Data = Player;

			if (Player.bStatus) {
				Connected->AddItem(EntryData);
			}
			else {
				Disconnected->AddItem(EntryData);
			}
		}
	}
	return true;
}

void UUFriendListWidget::onFriendUpdate_Implementation(const FPlayerData& Player)
{
	// selecting the list to add or remove the player
	UListView* AddingList = Player.bStatus ? Connected : Disconnected;
	UListView* RemovingList = Player.bStatus ? Disconnected : Connected;

	// remove the player from the list
	for (int32 i = 0; i < RemovingList->GetNumItems(); i++) {
		UEntryListData* EntryData = Cast<UEntryListData>(RemovingList->GetItemAt(i));
		if (EntryData && EntryData->Data.PlayerNickname == Player.PlayerNickname) {
			RemovingList->RemoveItem(EntryData);
			break;
		}
	}

	// add the player to the list
	UEntryListData* EntryData = NewObject<UEntryListData>();
	EntryData->Data = Player;
	AddingList->AddItem(EntryData);

}



