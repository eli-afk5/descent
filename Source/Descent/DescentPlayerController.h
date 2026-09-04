// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "Public/PawnBase.h"
#include "DescentPlayerController.generated.h"

class UInputMappingContext;
class UUserWidget;

/**
 *  Simple first person Player Controller
 *  Manages the input mapping context.
 *  Overrides the Player Camera Manager class.
 */
UCLASS(abstract, config="Game")
class DESCENT_API ADescentPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	/** Constructor */
	ADescentPlayerController();
	
	UPROPERTY(EditAnywhere, Category="References")
	APawnBase* PlayerRef;

protected:

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> MobileExcludedMappingContexts;

	/** Mobile controls widget to spawn */
	UPROPERTY(EditAnywhere, Category="Input|Touch Controls")
	TSubclassOf<UUserWidget> MobileControlsWidgetClass;

	/** Pointer to the mobile controls widget */
	UPROPERTY()
	TObjectPtr<UUserWidget> MobileControlsWidget;

	/** If true, the player will use UMG touch controls even if not playing on mobile platforms */
	UPROPERTY(EditAnywhere, Config, Category = "Input|Touch Controls")
	bool bForceTouchControls = false;

	/* INPUT ACTIONS */
	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* AccelerateAction;
	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* PitchAction;
	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* RollAction;
	UPROPERTY(EditAnywhere, Category = "Input|Actions")
	UInputAction* YawAction;
	
	/** Gameplay initialization */
	virtual void BeginPlay() override;
	
	void OnPossess(APawn* Pawn) override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

	/** Returns true if the player should use UMG touch controls */
	bool ShouldUseTouchControls() const;
};
