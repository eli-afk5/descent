// Fill out your copyright notice in the Description page of Project Settings.


#include "EmergencyExitDoor.h"

#include "DescentGameInstance.h"
#include "PawnBase.h"
#include "Components/BoxComponent.h"

AEmergencyExitDoor::AEmergencyExitDoor()
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	CollisionBox->SetupAttachment(DoorMesh);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AEmergencyExitDoor::OnBeginOverlap);
}

void AEmergencyExitDoor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (!GI) { return; }
	
	if (GI->bIsNuclearReactorDestroyed)
	{
		OpenDoor();
	}
}

void AEmergencyExitDoor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!GI) { return; }
	
	if (GI->PlayerRef->EnergyCounter>100)
	{
		GI->PlayerRef->Score = GI->PlayerRef->Score + GI->PlayerRef->EnergyCounter * GI->EnergyPointsMultiplier;
	}
	if (GI->PlayerRef->ShieldCounter>100)
	{
		GI->PlayerRef->Score = GI->PlayerRef->Score + GI->PlayerRef->ShieldCounter * GI->ShieldPointsMultiplier;
	}
	if (GI->PlayerRef->HostagesCounter == GI->HostagesStackSize)
	{
		GI->PlayerRef->Score = GI->PlayerRef->Score + GI->HostagesPointsValue * GI->HostagesStackSize;
	}
}
