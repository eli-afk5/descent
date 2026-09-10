// Fill out your copyright notice in the Description page of Project Settings.


#include "HiddenDoor.h"

#include "DoorsData.h"
#include "Components/SphereComponent.h"

AHiddenDoor::AHiddenDoor()
{
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	CollisionSphere->SetupAttachment(DoorMesh);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AHiddenDoor::OnBeginOverlap);
}

void AHiddenDoor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!DoorDataAsset) { return; }
	DoorMesh->SetStaticMesh(DoorDataAsset->OpenDoorMesh);
}
