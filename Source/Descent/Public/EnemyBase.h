// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyBase.generated.h"

class UEnemiesData;

UCLASS()
class DESCENT_API AEnemyBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyBase();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Enemy Settings|Components")
	UStaticMeshComponent* EnemyMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy Settings|Data Asset")
	TObjectPtr<UEnemiesData> EnemyDataAsset;
	//TODO: add Pawn Sensing Component
	
	UFUNCTION(BlueprintCallable)
	virtual void OnPlayerDetected();
	UFUNCTION(BlueprintCallable)
	virtual void Attack(APawn* Target);
	UFUNCTION(BlueprintCallable)
	virtual void OnDestroyed();
	
};
