// Fill out your copyright notice in the Description page of Project Settings.


#include "Hostage.h"

#include "PawnBase.h"

void AHostage::BeginPlay()
{
	Super::BeginPlay();
	
	if (!GI) { return; }
	
	GI->HostagesStackSize = ItemDataAsset->StackSize;
	GI->HostagesPointsValue = ItemDataAsset->PointsValue;

}

void AHostage::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	if (!GI) { return; }
	if (OtherActor == GI->PlayerRef)
	{
		GI->PlayerRef->HostagesCounter = GI->PlayerRef->HostagesCounter + ItemDataAsset->UnitsAdded;
        	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Red, 
        		FString::Printf(TEXT("Hostages: %i"), GI->PlayerRef->HostagesCounter));
        	
        	GI->PlayerRef->Score = GI->PlayerRef->Score + ItemDataAsset->PointsValue;
	}
	
}

