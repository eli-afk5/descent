// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
#include "BossFightDoor.generated.h"

/**
 * 
 */
UCLASS()
class DESCENT_API ABossFightDoor : public ADoorBase
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;
};
