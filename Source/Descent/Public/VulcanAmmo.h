// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AmmoBase.h"
#include "VulcanAmmo.generated.h"

/**
 * 
 */
UCLASS()
class DESCENT_API AVulcanAmmo : public AAmmoBase
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(BlueprintReadWrite)
	int UnitsDropped = 0;
	
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
