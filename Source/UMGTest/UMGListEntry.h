// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UMGListEntry.generated.h"

/**
 * 
 */
UCLASS()
class UMGTEST_API UUMGListEntry : public UCommonActivatableWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FString Description;

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Field;

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
};
