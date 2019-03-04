// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	MovingplatformSpeed = 20;
}

void AMovingPlatform::Tick(float DeltaSeconds)
{

	if (HasAuthority())
	{
		FVector Location = GetActorLocation();
		FVector GolbalTargetLocation = GetTransform().TransformPosition(TargetLocation);
		FVector Direction = (GolbalTargetLocation -Location).GetSafeNormal();

		Location += MovingplatformSpeed*DeltaSeconds*Direction;
		this->SetActorLocation(Location);
	}
	
	
}



void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
}
