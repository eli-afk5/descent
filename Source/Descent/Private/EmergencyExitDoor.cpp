// Fill out your copyright notice in the Description page of Project Settings.


#include "EmergencyExitDoor.h"

#include "DescentGameInstance.h"
#include "Kismet/GameplayStatics.h"

void AEmergencyExitDoor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (!GI) { return; }
	
	if (GI->bIsNuclearReactorDestroyed)
	{
		OpenDoor();
	}
}
