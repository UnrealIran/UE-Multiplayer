// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/MainMenu.h"
UPuzzlePlatformGameInstance::UPuzzlePlatformGameInstance(const FObjectInitializer & ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MenuSystem"));
	if (!ensure(MenuBPClass.Class != nullptr)) { return; }
	MenuClass = MenuBPClass.Class;
	
}
void UPuzzlePlatformGameInstance::Init()
{
	Super::Init();
	
	UE_LOG(LogTemp, Warning, TEXT("It is found %s"), *MenuClass->GetName())
}

void UPuzzlePlatformGameInstance::LoadMenu()
{
	if (!ensure(MenuClass != nullptr)) { return; }
	UMainMenu* Menu = CreateWidget<UMainMenu>(this, MenuClass);
	if (!ensure(Menu != nullptr)) { return; }
	Menu->SetUp();
	Menu->SetMenuInterface(this);
}


void UPuzzlePlatformGameInstance::Host()
{
	GEngine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("Hosting"));
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) { return; }
	World->ServerTravel("/Game/Maps/ThirdPersonExampleMap?listen");
	
}

void UPuzzlePlatformGameInstance::Join(const FString& Address)
{
	GEngine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joing %s"),*Address));
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) { return; }
	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
