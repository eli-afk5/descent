// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
#include "HiddenDoor.generated.h"

class USphereComponent;
/**
 * 
 */
UCLASS()
class DESCENT_API AHiddenDoor : public ADoorBase
{
	GENERATED_BODY()
	
public:
	AHiddenDoor();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door Settings|Components")
	USphereComponent* CollisionSphere;
	UPROPERTY(BlueprintReadOnly, Category = "Door Settings|Misc")
	FTimerHandle TimerHandle;
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
	void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
