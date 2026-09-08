// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/PawnBase.h"

#include "DescentGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void APawnBase::BeginPlay()
{
	Super::BeginPlay();
	
	GI = Cast<UDescentGameInstance>(UGameplayStatics::GetGameInstance(this));
	if (GI)
	{
		GI->PlayerRef = this;
	}
	
}

// Called every frame
void APawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void APawnBase::DoToggleMap_Implementation()
{
}

void APawnBase::DoSwitchView_Implementation()
{
}

void APawnBase::DoDropBomb_Implementation()
{
}

void APawnBase::DoFireFlare_Implementation()
{
}

void APawnBase::DoFireSecondary_Implementation()
{
}

void APawnBase::DoFirePrimary_Implementation()
{
}

void APawnBase::DoSlideHorizontal_Implementation(float Value)
{
}

void APawnBase::DoSlideVertical_Implementation(float Value)
{
}

void APawnBase::DoYaw_Implementation(float Value)
{
}

void APawnBase::DoRoll_Implementation(float Value)
{
}

void APawnBase::DoPitch_Implementation(float Value)
{
}

void APawnBase::DoAccelerate_Implementation(float Value)
{
}
