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


