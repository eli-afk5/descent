// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyCard.h"
#include "BossFightDoor.h"

void AKeyCard::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	
	UnlockDoor()
}

void AKeyCard::UnlockDoor(ABossFightDoor* Door)
{
	Door->OpenDoor();
}
