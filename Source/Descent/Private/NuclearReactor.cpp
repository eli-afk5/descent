// Fill out your copyright notice in the Description page of Project Settings.


#include "NuclearReactor.h"

#include "PawnBase.h"
#include "Kismet/GameplayStatics.h"

void ANuclearReactor::OnDestroyed()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, 
	FString::Printf(TEXT("Nuclear Reactor destroyed")));
	
	if (GI)
	{
		GI->bIsNuclearReactorDestroyed = true;
	}
	
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ANuclearReactor::OnTimerOver, 45.f, false);
	
	Super::OnDestroyed();
}

void ANuclearReactor::OnTimerOver()
{
	GI->PlayerRef->OnDeath();
	
	if (GI->PlayerRef->LifeCounter > 0)
	{
		GI->PlayerRef->OnWin();
	}
}
