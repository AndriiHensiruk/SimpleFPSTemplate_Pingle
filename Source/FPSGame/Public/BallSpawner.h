// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/CoreUObject/Public/UObject/Object.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Engine/Public/TimerManager.h"
#include "Public/DrawDebugHelpers.h"
#include "Runtime/Engine/Public/EngineUtils.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "BallActor.h"
#include "BallSpawner.generated.h"

USTRUCT(BlueprintType)
struct FBallSpawnInfo
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		TArray<TSubclassOf<ABallActor>> actors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		TArray<AActor*> spawnedActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		int32 itemCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float spawnRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float destroyRadius;
};

UCLASS()
class FPSGAME_API ABallSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABallSpawner();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnSpawn();

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ball")
		TArray<FBallSpawnInfo> BallSpawnInfos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ball")
		TSubclassOf<AActor> TargetOriginClass;

private:
	FTimerHandle hSpawnTimer;
	AActor* target;
	void SpawnActor(FBallSpawnInfo& si);
};
