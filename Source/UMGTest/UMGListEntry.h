// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UMGListEntry.generated.h"

/**
 * 
 */
UCLASS()
class UMGTEST_API UUMGListEntry : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Field;

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
};
