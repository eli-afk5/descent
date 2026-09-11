// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorBase.generated.h"

class UDescentGameInstance;
class UDoorsData;

UCLASS()
class DESCENT_API ADoorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Door Settings|Components")
	UStaticMeshComponent* DoorMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Door Settings|Data Asset")
	TObjectPtr<UDoorsData> DoorDataAsset;
	UPROPERTY()
	UDescentGameInstance* GI;

	UFUNCTION()
	virtual void OpenDoor();
	UFUNCTION()
	virtual void CloseDoor();

};
