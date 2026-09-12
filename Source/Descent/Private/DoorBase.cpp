// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorBase.h"

#include "DescentGameInstance.h"
#include "DoorsData.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADoorBase::ADoorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
}

// Called when the game starts or when spawned
void ADoorBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (DoorDataAsset)
	{
		DoorMesh->SetStaticMesh(DoorDataAsset->ClosedDoorMesh);
	}

	GI = Cast<UDescentGameInstance>(UGameplayStatics::GetGameInstance(this));
}

// Called every frame
void ADoorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorBase::OpenDoor()
{
	if (!DoorDataAsset) { return; }
	DoorMesh->SetStaticMesh(DoorDataAsset->OpenDoorMesh);
}

void ADoorBase::CloseDoor()
{
	if (!DoorDataAsset) { return; }
	DoorMesh->SetStaticMesh(DoorDataAsset->ClosedDoorMesh);
}
