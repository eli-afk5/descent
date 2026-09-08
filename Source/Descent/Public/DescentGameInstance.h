// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DescentGameInstance.generated.h"

class APawnBase;
/**
 * 
 */
UCLASS()
class DESCENT_API UDescentGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category = "Game Istance|References")
	APawnBase* PlayerRef;
	UPROPERTY(BlueprintReadWrite, Category = "Game Istance|Variables")
	bool bIsNuclearReactorDestroyed = false;
	
};
