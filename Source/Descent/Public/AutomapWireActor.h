// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AutomapWireActor.generated.h"

class UInstancedStaticMeshComponent;
class UAutomapWireData;

UCLASS()
class DESCENT_API AAutomapWireActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAutomapWireActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, Category = "Automap Settings")
	TObjectPtr<UAutomapWireData> Data;
	UPROPERTY(EditAnywhere, Category = "Automap Settings")
	float Thickness = 5.f;
	UPROPERTY(EditAnywhere, Category = "Automap Settings")
	TObjectPtr<UMaterialInterface> WireMaterial;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Automap Settings")
	TObjectPtr<UInstancedStaticMeshComponent> ISM;
	
public:
	UFUNCTION(BlueprintCallable, Category = "Automap Actions")
	void RebuildInstances();



};
