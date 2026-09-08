// Fill out your copyright notice in the Description page of Project Settings.


#include "ShieldBooster.h"

#include "PawnBase.h"

void AShieldBooster::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	GI->PlayerRef->ShieldCounter = GI->PlayerRef->ShieldCounter + ItemDataAsset->UnitsAdded;
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, 
		FString::Printf(TEXT("Shield: %i"), GI->PlayerRef->ShieldCounter));
}


