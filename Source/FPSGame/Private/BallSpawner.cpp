// Fill out your copyright notice in the Description page of Project Settings.


#include "BallSpawner.h"



// Sets default values
ABallSpawner::ABallSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1;

}



// Called when the game starts or when spawned
void ABallSpawner::BeginPlay()
{
	Super::BeginPlay();
	//
	
	
}

void ABallSpawner::OnSpawn()
{
}


// Called every frame
void ABallSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TArray<AActor*> deletes;

	for (auto& ins : BallSpawnInfos) {

		for (int i = 0; i < ins.spawnedActors.Num(); i++) {
			AActor* a = ins.spawnedActors[i];
			float distanse = UKismetMathLibrary::Vector_Distance(a->GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
			if (distanse > ins.destroyRadius)
			{
				deletes.Add(a);

				a->Destroy();
				UE_LOG(LogTemp, Log, TEXT("Destroyed %p %d %s"), a, a->GetUniqueID(), *a->GetFName().ToString());
			}
		}
		if (ins.spawnedActors.Num() < ins.itemCount) {
			SpawnActor(ins);
		}
	}
}

void ABallSpawner::SpawnActor(FBallSpawnInfo& si)
{
	if (si.actors.Num()) {
		UClass* c = si.actors[0];
		if (c)
		{
			FVector origin = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
			FRotator actorRotation = FRotator::ZeroRotator;
			FActorSpawnParameters p;
			p.Owner = this;

			AActor* a = GetWorld()->SpawnActor(si.actors[0], &origin, &actorRotation, p);

			int idx = si.spawnedActors.Add(a);

			UE_LOG(LogTemp, Log, TEXT("Spawned %p %d %s"), a, a->GetUniqueID(), *a->GetFName().ToString());
		}
	}
}

