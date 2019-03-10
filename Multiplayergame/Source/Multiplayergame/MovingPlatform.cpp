// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Platformtrigger.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	MovingplatformSpeed = 20;
	
}


void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

}



void AMovingPlatform::Tick(float DeltaSeconds)
{
	if (ActiveTriggers > 0) {

		if (HasAuthority())
		{
			FVector Location = GetActorLocation();

			float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
			float JourneyTravelled = (Location - GlobalStartLocation).Size();

			if (JourneyTravelled >= JourneyLength)
			{
				FVector Swap = GlobalStartLocation;
				GlobalStartLocation = GlobalTargetLocation;

				GlobalTargetLocation = Swap;
			}
			FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

			Location += MovingplatformSpeed * DeltaSeconds*Direction;
			this->SetActorLocation(Location);

		}

	}
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;

}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers >0)
		{
		ActiveTriggers--;
		}

}

