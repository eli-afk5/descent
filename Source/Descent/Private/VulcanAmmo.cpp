// Fill out your copyright notice in the Description page of Project Settings.


#include "VulcanAmmo.h"

#include "PawnBase.h"

void AVulcanAmmo::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	GI->PlayerRef->VulcanAmmoCounter = GI->PlayerRef->VulcanAmmoCounter + ItemDataAsset->UnitsAdded;
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, 
		FString::Printf(TEXT("Vulcan Cannon ammo: %i"), GI->PlayerRef->VulcanAmmoCounter));
}
