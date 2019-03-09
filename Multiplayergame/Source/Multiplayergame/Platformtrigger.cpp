// Fill out your copyright notice in the Description page of Project Settings.

#include "Platformtrigger.h"
#include "Components/BoxComponent.h"
// Sets default values
APlatformtrigger::APlatformtrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerVolume = CreateDefaultSubobject<UBoxComponent>("Trigger Volume");
	RootComponent = TriggerVolume;
	TriggerVolume->SetGenerateOverlapEvents(true);
	if (!ensure(TriggerVolume != nullptr)) return;
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformtrigger::OnOverlapBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformtrigger::OnOvelapEnd);
}

// Called when the game starts or when spawned
void APlatformtrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformtrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformtrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp,Warning,TEXT("You entered"))
}

void APlatformtrigger::OnOvelapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("You Close from ovelap"))
}

