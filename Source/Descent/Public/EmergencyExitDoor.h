// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
#include "EmergencyExitDoor.generated.h"

class AItemBase;
class AHostage;
class AShieldBooster;
class AEnergyBooster;
class UBoxComponent;
class UDescentGameInstance;
/**
 * 
 */
UCLASS()
class DESCENT_API AEmergencyExitDoor : public ADoorBase
{
	GENERATED_BODY()
	
public:	
	AEmergencyExitDoor();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door Settings|Components")
	UBoxComponent* CollisionBox;	
	
	virtual void Tick(float DeltaSeconds) override;
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
