// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UFriendListWidget.generated.h"

class UListView;
struct FPlayerData;
/**
 * 
 */
UCLASS()
class UMGTEST_API UUFriendListWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	UListView* Connected;

	UPROPERTY(meta = (BindWidget))
	UListView* Disconnected;

protected:
	virtual bool Initialize() override;

public:
	UFUNCTION(BlueprintNativeEvent)
	void onFriendUpdate(const FPlayerData& Player);

	void onFriendUpdate_Implementation(const FPlayerData& Player);
};
