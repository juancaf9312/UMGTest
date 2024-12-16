// Fill out your copyright notice in the Description page of Project Settings.


#include "UFrindLIstMock.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

void UMockList::UpdateRandomFriend()
{
	// get a random friend
	FPlayerData* Friend = &FriendList[FMath::RandRange(0, FriendList.Num() - 1)];
	if (Friend)
	{
		UE_LOG(LogTemp, Warning, TEXT("Changing state of %s"), *Friend->PlayerNickname)
		// update the friend status
		Friend->bStatus = !Friend->bStatus;
		OnFriendUpdate.Broadcast(*Friend);
	}

	// setup event again
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UMockList::UpdateRandomFriend, FMath::FRandRange(15., 25.), true);
}

UMockList::UMockList()
{
	// find Data Table on the project assets
	UDataTable* MockData = ConstructorHelpers::FObjectFinder<UDataTable>(TEXT("DataTable'/Game/UMGTest/Data/DT_MockData'")).Object;
	if (MockData)
	{
		// get all rows from the data table
		TArray<FPlayerData*> MockDataArray;
		MockData->GetAllRows<FPlayerData>(TEXT("MockData"), MockDataArray);

		// iterate over all rows
		for (FPlayerData* Data : MockDataArray)
		{
			// add the row to the list
			FriendList.Add(*Data);
		}
	}
}

void UMockList::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UMockList::UpdateRandomFriend, FMath::FRandRange(5., 15.), true);
}

