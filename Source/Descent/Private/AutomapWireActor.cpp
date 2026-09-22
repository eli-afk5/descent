// Fill out your copyright notice in the Description page of Project Settings.


#include "AutomapWireActor.h"
#include "AutomapWireActor.h"
#include "AutomapWireData.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AAutomapWireActor::AAutomapWireActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ISM = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ISM"));
	SetRootComponent(ISM);
	ISM->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ISM->SetCastShadow(false);
	ISM->SetMobility(EComponentMobility::Static);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMesh.Succeeded())
	{
		ISM->SetStaticMesh(CubeMesh.Object);
	}
	
}

// Called when the game starts or when spawned
void AAutomapWireActor::BeginPlay()
{
	Super::BeginPlay();

	RebuildInstances();
	
}

// Called every frame
void AAutomapWireActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAutomapWireActor::RebuildInstances()
{
	ISM->ClearInstances();

	if (WireMaterial)
	{
		ISM->SetMaterial(0, WireMaterial);
	}
	
	if (!Data)
	{
		UE_LOG(LogTemp, Warning, TEXT("AAutomapWireActor::RebuildInstances - Data Asset not assigned"));
		return;
	}

	TArray<FTransform> Xf;
	Xf.Reserve(Data->Lines.Num() / 2);

	for (int32 i = 0; i + 1 < Data->Lines.Num(); i += 2)
	{
		const FVector A = Data->Lines[i];
		const FVector B = Data->Lines[i + 1];
		const FVector D = B - A;
		const float L = D.Size();
		if (L < 1.f) continue;

		//Base UE cube measures 100uu; scale for desired measurements
		Xf.Emplace(
			FRotationMatrix::MakeFromZ(D).ToQuat(),
			(A + B) * 0.5f,
			FVector(Thickness / 100.f, Thickness / 100.f, L / 100.f)
		);
	}

	ISM->AddInstances(Xf, false, false);
	UE_LOG(LogTemp, Log, TEXT("AAutomapWireActor::RebuildInstances - %d instances created"), Xf.Num());
}