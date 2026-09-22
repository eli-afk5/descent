// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AutomapWireData.generated.h"

/**
 * 
 */
UCLASS()
class DESCENT_API UAutomapWireData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere) TArray<FVector> Lines; //pairs of points in world space
};
