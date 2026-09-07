// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemsData.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

class USphereComponent;

UCLASS()
class DESCENT_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item Settings|Components")
	UStaticMeshComponent* ItemMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Settings|Components")
	USphereComponent* CollisionSphere; //collision sphere of the item (for pickup)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Settings|Data Asset")
	TObjectPtr<UItemsData> ItemDataAsset;
	
	//triggers OnPickup function in UItemsData
	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
