// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DescentGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DESCENT_API UDescentGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Game Istance|Game Objects")
	bool bIsNuclearReactorDestroyed = false;
	
};
