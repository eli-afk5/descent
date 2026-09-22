// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AutomapWireBuilder.generated.h"

class UAutomapWireData;

UCLASS()
class DESCENT_API AAutomapWireBuilder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAutomapWireBuilder();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = "Builder Settings|Automap")
	TObjectPtr<UAutomapWireData> Target;

	UPROPERTY(EditAnywhere, Category = "Builder Settings|Automap")
	FName SourceTag = "AutomapSource";

	UPROPERTY(EditAnywhere, Category = "Builder Settings|Automap")
	float AngleDeg = 20.f;

#if WITH_EDITOR
	UFUNCTION(CallInEditor, Category = "Builder Settings")
	void Bake();
#endif

private:
	//Extracts lines (pairs of points, local space) from the sides ("features") of a static mesh
	static void ExtractFeatureEdges(const UStaticMesh* Mesh, float InAngleDeg, TArray<FVector>& OutLines);

};
