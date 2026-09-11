// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
#include "DestroyableDoor.generated.h"

/**
 * 
 */
UCLASS()
class DESCENT_API ADestroyableDoor : public ADoorBase
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door ViewModel",
	meta=(ToolTip = "Static Mesh to be assigned to the door when it fractures the first time."))
	UStaticMesh* FirstFractureDoorMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door ViewModel",
		meta=(ToolTip = "Static Mesh to be assigned to the door when it fractures the second time."))
	UStaticMesh* SecondFractureDoorMesh;
	
	UFUNCTION(BlueprintCallable, Category = "Door Actions|Debug Actions") //temporary
	void DebugDestruction();
	UFUNCTION(BlueprintCallable, Category = "Door Actions|Debug Actions") //temporary
	void DebugFirstFracture();
	UFUNCTION(BlueprintCallable, Category = "Door Actions|Debug Actions") //temporary
	void DebugSecondFracture();
};
