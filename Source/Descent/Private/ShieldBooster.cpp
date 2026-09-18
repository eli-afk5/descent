// Fill out your copyright notice in the Description page of Project Settings.


#include "ShieldBooster.h"

#include "PawnBase.h"

void AShieldBooster::BeginPlay()
{
	Super::BeginPlay();
	
	if (!GI) { return; }
	
	GI->ShieldPointsMultiplier = ItemDataAsset->PointsMultiplier;
}

void AShieldBooster::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	if (!GI) { return; }
	if (OtherActor == GI->PlayerRef)
	{
		GI->PlayerRef->ShieldCounter = FMath::Clamp(
             		GI->PlayerRef->ShieldCounter + ItemDataAsset->UnitsAdded, 0, ItemDataAsset->StackSize);
	}
	
}


