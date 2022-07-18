// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereTrace.h"
#include "FPSRoomFloor.h"
#include "GameFramework/Actor.h"





// Sets default values for this component's properties
USphereTrace::USphereTrace()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USphereTrace::BeginPlay()
{
	Super::BeginPlay();

	// ...
	ChekBall();
}


// Called every frame
void USphereTrace::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	//ChekBall();
}

void USphereTrace::ChekBall()
{
	TArray<FHitResult> HitArray;
	
	const FVector Start = GetOwner()->GetActorLocation();
	const FVector End = GetOwner()->GetActorLocation();

	/*const FCollisionShape ColShape = FCollisionShape::MakeSphere(TracerRadius);
	const bool Hit = GetWorld()->SweepMultiByChannel(HitResults, Start, End, FQuat::Identity, ECC_Camera, ColShape);*/

	TArray<AActor*> ActorsToIgnor;

	ActorsToIgnor.Add(GetOwner());

	const bool Hit = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), Start, End, TracerRadius, UEngineTypes::ConvertToTraceType(ECC_Camera),
		false, ActorsToIgnor, EDrawDebugTrace::ForDuration, HitArray, true, FLinearColor::Gray, FLinearColor::Blue, 60.0f);
	//DrawDebugSphere(GetWorld(), Start, TracerRadius, 50, FColor::Orange, true);

	//
	
	if (Hit)
	{
		for (const FHitResult HitResult : HitArray)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 60.0f, FColor::Orange, FString::Printf(TEXT("Hit: %s"), *HitResult.Actor->GetName()));
		}
	}

	

}

