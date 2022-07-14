// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BallSpawner.h"
#include "FPSCharacter.h"
#include "FPSGameMode.generated.h"

UCLASS()
class AFPSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	AFPSGameMode();
	/** ball spawn component  */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ball")
		ABallSpawner* BallSpawner;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FPSCharacter")
		AFPSCharacter* FPSCharacter;

	UFUNCTION(BlueprintCallable, Category = "Score")
		void GetScore();
};



