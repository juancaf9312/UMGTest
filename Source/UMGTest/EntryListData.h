// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerData.h"
#include "EntryListData.generated.h"

/**
 * 
 */
UCLASS()
class UMGTEST_API UEntryListData : public UObject
{
	GENERATED_BODY()
	
public:
	FPlayerData Data;
};
