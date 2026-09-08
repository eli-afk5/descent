// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UDescentGameInstance;
class AItemBase;
class UItemsData;

UCLASS()
class DESCENT_API APawnBase : public APawn
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	float MovementSpeed = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	float RotationSpeed = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	bool bHasKey = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	int EnergyCounter = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	int ShieldCounter = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	int HostagesCounter = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	int ConcussionCounter = 6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	bool bHasVulcanCannon = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	int VulcanAmmoCounter = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Variables")
	int HomingMissilesCounter = 0;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Settings|Data Asset")
	TMap<FName, TSubclassOf<UItemsData>> DataMap;
	UPROPERTY()
	UDescentGameInstance* GI;
	
	// Sets default values for this pawn's properties
	APawnBase();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//ACTIONS
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoAccelerate(float Value);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoPitch(float Value);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoRoll(float Value);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoYaw(float Value);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoSlideHorizontal(float Value);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoSlideVertical(float Value);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoFirePrimary();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoFireSecondary();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoFireFlare();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoDropBomb();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoSwitchView();
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Actions")
	void DoToggleMap();
	
};
