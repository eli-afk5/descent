// Fill out your copyright notice in the Description page of Project Settings.


#include "EmergencyExitDoor.h"

#include "DescentGameInstance.h"
#include "Kismet/GameplayStatics.h"

void AEmergencyExitDoor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	GI = Cast<UDescentGameInstance>(UGameplayStatics::GetGameInstance(this));
	
	if (!GI) { return; }
	
	if (GI->bIsNuclearReactorDestroyed)
	{
		OpenDoor();
	}
}
