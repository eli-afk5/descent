// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemsData.h"
#include "AmmoData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class DESCENT_API UAmmoData : public UItemsData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Item Information",
		meta=(ToolTip = "Value to multiply baseline damage amount by."))
	float DamageMultiplier;
};
