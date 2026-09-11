// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
#include "BossFightDoor.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class DESCENT_API ABossFightDoor : public ADoorBase
{
	GENERATED_BODY()
	
public:
	ABossFightDoor();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door Settings|Components")
	USphereComponent* CollisionSphere;
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
	void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
