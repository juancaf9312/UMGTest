// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UFriendListWidget.generated.h"

class UListView;

/**
 * 
 */
UCLASS()
class UMGTEST_API UUFriendListWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	UListView* Connected;

	UPROPERTY(meta = (BindWidget))
	UListView* Disconnected;

protected:
	virtual bool Initialize() override;
};