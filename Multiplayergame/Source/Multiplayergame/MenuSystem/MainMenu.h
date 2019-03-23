// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERGAME_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual bool Initialize() override;
	//Host Server
	UFUNCTION()
	void HostButtonClicked();
	//It actives when push join menu
	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void BackToHostMenu();
	//Join server
	UFUNCTION()
	void JoinButtonClicked();


	void SetMenuInterface(class IMenuInterface* MenuInterface) { this->MenuInterface = MenuInterface; }

	void SetUp();

	void TearDown();

	virtual void OnLevelRemovedFromWorld(ULevel * InLevel, UWorld * InWorld) override;

private:
	UPROPERTY(meta=(BindWidget))
	class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;
	//widgets for switch
	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu;
	//second pages buttons
	UPROPERTY(meta = (BindWidget))
	class UButton* BackButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAddressTextField;
	 
	class IMenuInterface* MenuInterface;
};
