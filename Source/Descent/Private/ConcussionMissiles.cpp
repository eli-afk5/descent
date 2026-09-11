// Fill out your copyright notice in the Description page of Project Settings.


#include "ConcussionMissiles.h"

#include "PawnBase.h"

void AConcussionMissiles::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	if (!GI) { return; }
	
	GI->PlayerRef->ConcussionCounter = FMath::Clamp(
		GI->PlayerRef->ConcussionCounter + ItemDataAsset->UnitsAdded, 0, ItemDataAsset->StackSize);
//	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, 
//		FString::Printf(TEXT("Concussion: %i"), GI->PlayerRef->ConcussionCounter));
}
