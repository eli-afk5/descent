// Fill out your copyright notice in the Description page of Project Settings.


#include "HomingMissile.h"

#include "PawnBase.h"

void AHomingMissile::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	if (!GI) { return; }
	
	GI->PlayerRef->HomingMissilesCounter = FMath::Clamp(
		GI->PlayerRef->HomingMissilesCounter + ItemDataAsset->UnitsAdded, 
		0, ItemDataAsset->StackSize);
//	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, 
//		FString::Printf(TEXT("HomingMissiles: %i"), GI->PlayerRef->HomingMissilesCounter));
}
