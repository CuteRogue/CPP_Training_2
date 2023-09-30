// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle/MovingPlatform.h"

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

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
	Rotate(DeltaTime);
}

void AMovingPlatform::Move(const float DeltaTime)
{
	if (MaxDistance <= 0)
	{ return; }
	
	if (IsMaxDistanceReached())
	{
		OnMaxDistanceReached();
		return;
	}
	
	SetActorLocation(GetNewPosition(DeltaTime));
}

void AMovingPlatform::OnMaxDistanceReached()
{
	const FVector MoveDirection = MoveVelocity.GetSafeNormal();
	StartLocation = StartLocation + MoveDirection * MaxDistance;
	SetActorLocation(StartLocation);
	
	MoveVelocity = -MoveVelocity;
}


void AMovingPlatform::Rotate(const float DeltaTime)
{
	AddActorLocalRotation(RotateVelocity * DeltaTime);
}

bool AMovingPlatform::IsMaxDistanceReached() const
{
	return FVector::Dist(GetActorLocation(), StartLocation) > MaxDistance;
}

FVector AMovingPlatform::GetNewPosition(const float DeltaTime) const
{
	return GetActorLocation() + MoveVelocity * DeltaTime;
}








