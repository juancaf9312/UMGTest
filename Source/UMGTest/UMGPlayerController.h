// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UMGPlayerController.generated.h"

class UUserWidget;

/**
 * 
 */
UCLASS()
class UMGTEST_API AUMGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UUserWidget> WidgetClass;

	UUserWidget* FriendListWidget;
public:
	void BeginPlay() override;
	void SetupInputComponent() override;

	void ShowWidget();
	void HideWidget();
};
