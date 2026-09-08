// Fill out your copyright notice in the Description page of Project Settings.


#include "EnergyBooster.h"

#include "PawnBase.h"

void AEnergyBooster::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	GI->PlayerRef->EnergyCounter++;
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, 
		FString::Printf(TEXT("Energy: %i"), GI->PlayerRef->EnergyCounter));
}
