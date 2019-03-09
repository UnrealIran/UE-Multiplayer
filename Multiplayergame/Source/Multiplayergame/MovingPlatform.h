// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERGAME_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
public:
	AMovingPlatform();
protected:

	virtual void Tick(float DeltaSeconds) override;
	

	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere)
	int32 MovingplatformSpeed;


	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = true))
		FVector TargetLocation;

private:
	FVector GlobalTargetLocation;

	FVector GlobalStartLocation;

};
