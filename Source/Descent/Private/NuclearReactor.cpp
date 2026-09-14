// Fill out your copyright notice in the Description page of Project Settings.


#include "NuclearReactor.h"

#include "Kismet/GameplayStatics.h"

void ANuclearReactor::OnDestroyed()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, 
	FString::Printf(TEXT("Nuclear Reactor destroyed")));
	
	if (GI)
	{
		GI->bIsNuclearReactorDestroyed = true;
	}
	
	Super::OnDestroyed();
}
