// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "NuclearReactor.generated.h"

/**
 * 
 */
UCLASS()
class DESCENT_API ANuclearReactor : public AEnemyBase
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(BlueprintReadOnly, Category = "Nuclear Reactor|Timer")
	FTimerHandle TimerHandle;
	
	virtual void OnDestroyed() override;
	void OnTimerOver();
	UFUNCTION(BlueprintNativeEvent)
	void CreateTimer();
};
