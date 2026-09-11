// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyableDoor.h"

#include "DestroyableDoorData.h"
#include "DoorsData.h"

void ADestroyableDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (DoorDataAsset)
	{
		if (DoorDataAsset->HP == 6)
		{
			DoorMesh->SetStaticMesh(FirstFractureDoorMesh);
		}
		
		if (DoorDataAsset->HP == 3)
		{
			DoorMesh->SetStaticMesh(SecondFractureDoorMesh);
		}
		
		if (DoorDataAsset->HP == 0) { OpenDoor(); }
	}
}

void ADestroyableDoor::DebugDestruction()
{
	if (!DoorDataAsset) { return; }
	DoorDataAsset->HP = 0;
}

void ADestroyableDoor::DebugFirstFracture()
{
	if (!DoorDataAsset) { return; }
	DoorDataAsset->HP = 6;
}
void ADestroyableDoor::DebugSecondFracture()
{
	if (!DoorDataAsset) { return; }
	DoorDataAsset->HP = 3;
}
