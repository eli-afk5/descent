// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnemiesData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class DESCENT_API UEnemiesData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Enemy Information")
	FName Name; //display name of the enemy
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Enemy Information")
	FName Description; //description of the enemy
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Enemy ViewModel")
	UStaticMesh* StaticMesh; //static mesh of the enemy
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Enemy Information")
	float HP; //HP of the enemy (in laser shots)
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Enemy Information")
	float AttackPower; //attack power of the enemy (in weapon shots)
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Enemy Information",
		meta=(ToolTip = "Value to multiply baseline fire rate by."))
	int FireRateMultiplier; //value to multiply baseline fire rate by
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Enemy Information")
	int AmountInLevel; //number of enemies spawned on begin play
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Enemy Information")
	int PointsValue; //points awarded upon destroying the enemy

};
