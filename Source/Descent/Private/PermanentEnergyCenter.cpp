// Fill out your copyright notice in the Description page of Project Settings.


#include "PermanentEnergyCenter.h"

#include "DescentGameInstance.h"
#include "PawnBase.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APermanentEnergyCenter::APermanentEnergyCenter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APermanentEnergyCenter::OnBeginOverlap);
	
}

// Called when the game starts or when spawned
void APermanentEnergyCenter::BeginPlay()
{
	Super::BeginPlay();
	
	GI = Cast<UDescentGameInstance>(UGameplayStatics::GetGameInstance(this));
}

// Called every frame
void APermanentEnergyCenter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APermanentEnergyCenter::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!GI) { return; }
	
	GI->PlayerRef->EnergyCounter = FMath::Clamp(
		GI->PlayerRef->EnergyCounter + RechargedEnergyUnits, 0, 200);
}
