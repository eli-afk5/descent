// Fill out your copyright notice in the Description page of Project Settings.


#include "VulcanCannon.h"

#include "PawnBase.h"

void AVulcanCannon::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	if (!GI) { return; }
	
	if (!GI->PlayerRef->bHasVulcanCannon)
	{
		GI->PlayerRef->bHasVulcanCannon = true;
//		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Turquoise, 
//			FString::Printf(TEXT("Vulcan Cannon picked up!")));
	
		GI->PlayerRef->VulcanAmmoCounter = FMath::Clamp(
			GI->PlayerRef->VulcanAmmoCounter + 2500, 0, ItemDataAsset->StackSize);
//		GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Turquoise, 
//		FString::Printf(TEXT("2500 ammunition units added automatically.")));
	}
	
}

