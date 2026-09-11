// Fill out your copyright notice in the Description page of Project Settings.


#include "BossFightDoor.h"

#include "DescentGameInstance.h"
#include "Public/PawnBase.h"
#include "Components/SphereComponent.h"

ABossFightDoor::ABossFightDoor()
{
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	CollisionSphere->SetupAttachment(DoorMesh);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ABossFightDoor::OnBeginOverlap);
	CollisionSphere->OnComponentEndOverlap.AddDynamic(this, &ABossFightDoor::OnEndOverlap);
}

void ABossFightDoor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!GI) { return; }
	if (GI->PlayerRef->bHasKey)
	{
		OpenDoor();
	}
}

void ABossFightDoor::OnEndOverlap(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	CloseDoor();
}
