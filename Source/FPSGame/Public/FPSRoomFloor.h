// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallActor.h"
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

	

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Room, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* Floor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Room, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> BallClas;

	void SpawnItem(UClass* ItemToSpawn);
};
