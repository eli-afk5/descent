// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemsData.generated.h"

/**
 * 
 */
UCLASS()
class DESCENT_API UItemsData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Item Information")
	FName Name; //display name of the item
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Item Information")
	FName Description; //description of the item
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Item ViewModel")
	UStaticMesh* StaticMesh; //static mesh of the item
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Item Information",
		meta=(ToolTip = "How many units of this items the player has when starting a new game."))
	int InitialAmount; //how many units does the player starts the level with
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Item Information",
		meta=(ToolTip = "How many units of this items the player can store in inventory."))
	int StackSize; //max amount of item units the player can have
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Item Information",
		meta=(ToolTip = "How many units of this items are added to the player's inventory upon pickup."))
	int UnitsAdded; //how many units are added to the player's inventory upon pickup
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Item Information",
		meta=(ToolTip = "Whether this item is dropped or not upon player death."))
	bool bIsDropped; //the item is dropped when the player dies
	UPROPERTY(EditDefaultsOnly, BLueprintReadOnly, Category = "Item Information",
		meta=(ToolTip = "Whether this item is destroyed or not upon player death."))
	bool bIsDestroyed; //the item is destroyed when the player dies
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Item Actions", meta=(ForceAsFunction))
	void OnPickup(); //what happens when the item is picked up
	UFUNCTION(BlueprintImplementableEvent, Category = "Item Actions", meta=(ForceAsFunction))
	void UseItem(); //what happens when the item is used
};
