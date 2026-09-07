// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "NuclearReactor.generated.h"

class UDescentGameInstance;
/**
 * 
 */
UCLASS()
class DESCENT_API ANuclearReactor : public AEnemyBase
{
	GENERATED_BODY()
	
public:	
	
	UPROPERTY()
	UDescentGameInstance* GI;
	
	virtual void OnDestroyed() override;
};
