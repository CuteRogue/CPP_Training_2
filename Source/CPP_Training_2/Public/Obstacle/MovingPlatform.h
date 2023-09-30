// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class CPP_TRAINING_2_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Manual Setup
	UPROPERTY(EditAnywhere, Category="Movement")
	FVector MoveVelocity;
	UPROPERTY(EditAnywhere, Category="Movement")
	float MaxDistance;
	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotateVelocity;

	// Locally edited
	FVector StartLocation;

	void Move(float DeltaTime);
	void Rotate(float DeltaTime);
	void OnMaxDistanceReached();

	bool IsMaxDistanceReached() const;
	FVector GetNewPosition(float DeltaTime) const;
};
