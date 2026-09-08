// Fill out your copyright notice in the Description page of Project Settings.


#include "VulcanCannon.h"

#include "PawnBase.h"

void AVulcanCannon::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	GI->PlayerRef->bHasVulcanCannon = true;
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Turquoise, 
		FString::Printf(TEXT("Vulcan Cannon picked up!")));
	
	GI->PlayerRef->VulcanAmmoCounter = GI->PlayerRef->VulcanAmmoCounter + ItemDataAsset->InitialAmount;
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Turquoise, 
	FString::Printf(TEXT("%i ammunition units added automatically."), 
		ItemDataAsset->InitialAmount));
}

