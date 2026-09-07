// Fill out your copyright notice in the Description page of Project Settings.


#include "BossFightDoor.h"

#include "Kismet/GameplayStatics.h"
#include "Public/PawnBase.h"

void ABossFightDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	APawn* Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (!Pawn) { return; }
	
	APawnBase* PlayerRef = Cast<APawnBase>(Pawn);
	if (!PlayerRef) { return; }
	
	if (PlayerRef->bHasKey)
	{
		OpenDoor();
	}
}
