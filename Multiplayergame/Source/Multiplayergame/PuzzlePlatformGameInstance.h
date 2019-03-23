// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "PuzzlePlatformGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERGAME_API UPuzzlePlatformGameInstance : public UGameInstance ,public IMenuInterface
{
	GENERATED_BODY()
public:
	UPuzzlePlatformGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init() override;

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);

	UFUNCTION(Exec,BlueprintCallable)
	void LoadMenu();

	// void Host() override;

private:
	TSubclassOf<UUserWidget> MenuClass;

	class UMainMenu* Menu;
};
