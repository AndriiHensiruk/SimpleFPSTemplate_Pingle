// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallActor.h"
#include "SphereTrace.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SphereTrace.h"


#include "TimerManager.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/CoreUObject/Public/UObject/Object.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Engine/Public/TimerManager.h"
#include "DrawDebugHelpers.h"
#include "FPSRoomFloor.generated.h"



UCLASS()
class FPSGAME_API AFPSRoomFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSRoomFloor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	void SpawnBall();

	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		int32 NumOfBall = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelay = 0.1f;

	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ball")
		float StageMinDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ball")
		float StageMaxDelay;

	
	UPROPERTY(EditAnywhere, Category = "Ball")
		int32 TotalObject;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trace")
		float RadarDistance = 5000.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Trace")
		float RadarHeight = 500.f;


private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Room, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* Floor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Room, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> BallClas;
	

	FTimerHandle RadarSweepTimerHandle;

	void SpawnItem(UClass* ItemToSpawn);

	
	void CountBall();
	UFUNCTION()
	void RadarRaycast();
	UFUNCTION()
	void RadarSweepTimer();
	
};
