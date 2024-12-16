// Fill out your copyright notice in the Description page of Project Settings.


#include "UMGPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "UMGGameInstance.h"

void AUMGPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AUMGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("FriendList", IE_Pressed, this, &AUMGPlayerController::ShowWidget);
	InputComponent->BindAction("FriendList", IE_Released, this, &AUMGPlayerController::HideWidget);
}

void AUMGPlayerController::ShowWidget()
{
	FriendListWidget = CreateWidget<UUserWidget>(this, WidgetClass);
	
	if (FriendListWidget)
	{
		FriendListWidget->AddToViewport();

		FInputModeGameAndUI InputModeData;
		InputModeData.SetWidgetToFocus(FriendListWidget->TakeWidget());
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		SetInputMode(InputModeData);

		bShowMouseCursor = true;
	}

}

void AUMGPlayerController::HideWidget()
{
	if (FriendListWidget)
	{
		FriendListWidget->RemoveFromParent();
		FriendListWidget = nullptr;

		FInputModeGameOnly InputModeData;
		SetInputMode(InputModeData);

		bShowMouseCursor = false;
	}

}
