// Fill out your copyright notice in the Description page of Project Settings.


#include "HiddenDoor.h"

#include "DoorsData.h"
#include "Components/SphereComponent.h"

AHiddenDoor::AHiddenDoor()
{
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	CollisionSphere->SetupAttachment(DoorMesh);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AHiddenDoor::OnBeginOverlap);
	CollisionSphere->OnComponentEndOverlap.AddDynamic(this, &AHiddenDoor::OnEndOverlap);
}

void AHiddenDoor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!DoorDataAsset) { return; }
	OpenDoor();
	
	if (DoorDataAsset->bHasDuration)
	{
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AHiddenDoor::CloseDoor, 
			DoorDataAsset->Duration, false);
	}
}

void AHiddenDoor::OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!DoorDataAsset) { return; }
	
	if (!DoorDataAsset->bHasDuration)
	{
		CloseDoor();
	}
}
