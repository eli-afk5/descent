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
	ISM->SetNumCustomDataFloats(3);

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
	TArray<FName> SegmentCategories;
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
		
		const int32 SegIndex = i / 2;
		SegmentCategories.Add(Data->Categories.IsValidIndex(SegIndex) ? Data->Categories[SegIndex] : NAME_None);
	}

	TArray<int32> Indices = ISM->AddInstances(Xf, /*bShouldReturnIndices*/ true, /*bWorldSpace*/ false);

	for (int32 k = 0; k < Indices.Num(); ++k)
	{
		const FName Category = SegmentCategories[k];
		const FLinearColor Color = CategoryColors.Contains(Category) ? CategoryColors[Category] : DefaultColor;

		ISM->SetCustomDataValue(Indices[k], 0, Color.R);
		ISM->SetCustomDataValue(Indices[k], 1, Color.G);
		ISM->SetCustomDataValue(Indices[k], 2, Color.B);
	}
	
	UE_LOG(LogTemp, Log, TEXT("AAutomapWireActor::RebuildInstances - %d instances created"), Xf.Num());
}