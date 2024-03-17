// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	TextOutput = "BeginPlay";

	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move the plat forwards
		// get the current location
	FVector CurrentLocation = GetActorLocation();
		
		// add a vector to that loc
	CurrentLocation = CurrentLocation + PlatformVelocity*DeltaTime;
		// set the location

	SetActorLocation(CurrentLocation );
	// send it back if gone too far
		// check how far we moved
		// reverse direction if we went too far 

	float  DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if (DistanceMoved   > MoveDistance) {
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation+MoveDirection*MoveDistance;
		SetActorLocation(StartLocation);

		PlatformVelocity = -PlatformVelocity;
	}

	TextOutput = "Tick";


}

