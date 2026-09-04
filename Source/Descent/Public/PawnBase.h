// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

UCLASS()
class DESCENT_API APawnBase : public APawn
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	float MovementSpeed = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	float RotationSpeed = 200.0f;
	
	// Sets default values for this pawn's properties
	APawnBase();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//ACTIONS
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Components")
	void DoAccelerate(float Value);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Components")
	void DoPitch(float Value);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Components")
	void DoRoll(float Value);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Components")
	void DoYaw(float Value);
};
