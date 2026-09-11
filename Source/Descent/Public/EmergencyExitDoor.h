// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
#include "EmergencyExitDoor.generated.h"

class UDescentGameInstance;
/**
 * 
 */
UCLASS()
class DESCENT_API AEmergencyExitDoor : public ADoorBase
{
	GENERATED_BODY()
	
public:	
	virtual void Tick(float DeltaSeconds) override;
};
