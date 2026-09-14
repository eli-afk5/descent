// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PermanentEnergyCenter.generated.h"

class UDescentGameInstance;
class UBoxComponent;

UCLASS()
class DESCENT_API APermanentEnergyCenter : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APermanentEnergyCenter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Room Settings|Components")
	UBoxComponent* CollisionBox;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Room Settings")
	int RechargedEnergyUnits = 100;
	UPROPERTY()
	UDescentGameInstance* GI;
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
};
