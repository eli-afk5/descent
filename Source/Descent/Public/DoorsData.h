// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DoorsData.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class DESCENT_API UDoorsData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door Information")
	FName Name;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door Information")
	FName Description;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door ViewModel",
		meta=(ToolTip = "Static Mesh to be assigned to the door when it's open."))
	UStaticMesh* OpenDoorMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door ViewModel",
		meta=(ToolTip = "Static Mesh to be assigned to the door when it's closed."))
	UStaticMesh* ClosedDoorMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door Information")
	float HP;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door Information")
	bool bHasDuration = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Door Information")
	float Duration;

};
