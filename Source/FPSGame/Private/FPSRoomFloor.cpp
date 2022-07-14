// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSRoomFloor.h"

// Sets default values
AFPSRoomFloor::AFPSRoomFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);
}

// Called when the game starts or when spawned
void AFPSRoomFloor::BeginPlay()
{
	Super::BeginPlay();
	SpawnItem(BallClas);
	SpawnItem(BallClas);
	SpawnItem(BallClas);
	SpawnItem(BallClas);
	SpawnItem(BallClas);
}

// Called every frame
void AFPSRoomFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSRoomFloor::SpawnItem(UClass* ItemToSpawn)
{
	float XCoordinate = FMath::FRandRange(-1000.f, 1000.f);
	float YCoordinate = FMath::FRandRange(-1000.f, 1000.f);

	float Yaw = FMath::FRandRange(0.f, 360.f);

	FVector Location(XCoordinate, YCoordinate, 300.f);
	FRotator Rotatoin(0.f, Yaw, 0.f);



	GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location, Rotatoin);
}

