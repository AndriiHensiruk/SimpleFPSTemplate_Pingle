// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSRoomFloor.h"
#include "DrawDebugHelpers.h"


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
	//
	SpawnBall();

	RadarRaycast();
	
	
}



void AFPSRoomFloor::SpawnBall()
{
	
	for (int i = 0; i < NumOfBall; i++) {
		SpawnItem(BallClas);
		//UE_LOG(LogTemp, Log, TEXT("Ball!!!"));
	}


	
}

// Called every frame
void AFPSRoomFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RadarSweepTimer();

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

void AFPSRoomFloor::CountBall()
{
	if (TotalObject < 19) 
	{
		ABallActor Ball ;
		Ball.DestroyBall();
		SpawnBall();
	}
	if (TotalObject == 0)
	{
		SpawnBall();
	}
}

void AFPSRoomFloor::RadarRaycast()
{
	//hold a reference to all the objects returned from our radar sweep
	TArray<FHitResult> RadarHitsArray;

	//use the ship location as the end location on the sphere, also set the height to be the radar height.
	FVector ShipLocation = GetActorLocation();
	//ShipLocation.Z += RadarHeight;

	FVector EndLocation = FVector(ShipLocation.X + 45.f, ShipLocation.Y, ShipLocation.Z);

	//Collision Shape is Spherical and range is 1km
	FCollisionShape RadarSphere = FCollisionShape::MakeSphere(RadarDistance);

	//Debug lines
	DrawDebugSphere(GetWorld(), ShipLocation, RadarDistance, 6, FColor::Yellow, true, 3.0f, 0U, 0.5f);

	//Now see what it hits	
	bool isHit = GetWorld()->SweepMultiByChannel(RadarHitsArray, ShipLocation, ShipLocation, FQuat::Identity, ECC_WorldStatic, RadarSphere);
	
	if (isHit)
	{
		for (auto& Hit : RadarHitsArray)
		{
			AActor* actor = Hit.GetActor();
			
			Hit.Component->GetName();
			if (GEngine)
			{
				if (actor && actor->GetName() == "BallActor") 
				{
					TotalObject++;
					UE_LOG(LogTemp, Log, TEXT("Hit  %s"));
				}
				TotalObject++;
			}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("TotalObjekt  %i, %s"), TotalObject);
}

void AFPSRoomFloor::RadarSweepTimer()
{
	GetWorld()->GetTimerManager().SetTimer(RadarSweepTimerHandle, this, &AFPSRoomFloor::RadarRaycast, 6.f, true, 0.5f);
}



