// Fill out your copyright notice in the Description page of Project Settings.


#include "UMGListEntry.h"
#include "EntryListData.h"
#include "Components/TextBlock.h"

void UUMGListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	UEntryListData* Data = Cast<UEntryListData>(ListItemObject);
	if (Data)
	{
		Field->SetText(FText::FromString(Data->Data.PlayerNickname));
	}
}