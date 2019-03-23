// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "MenuSystem/MenuInterface.h"
#include "Components/EditableTextBox.h"
bool UMainMenu::Initialize()
{
	bool Sucess=Super::Initialize();
	if (!Sucess) return false;
	if (!ensure(HostButton != nullptr)) return false;
	if (!ensure(JoinMenuButton != nullptr)) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostButtonClicked);
	JoinMenuButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::JoinButtonClicked);
	BackButton->OnClicked.AddDynamic(this, &UMainMenu::BackToHostMenu);
	return true;
}

void UMainMenu::HostButtonClicked()
{
	if (MenuInterface)
	{
		MenuInterface->Host();
	}
}

void UMainMenu::OpenJoinMenu()
{
	if (MenuSwitcher)
	{
		MenuSwitcher->SetActiveWidget(JoinMenu);
	}

}


void UMainMenu::JoinButtonClicked()
{
	if (MenuInterface) 
	{
		if (IPAddressTextField)
		{
			const FText& IPAddress = IPAddressTextField->GetText();
			// 		
			MenuInterface->Join(IPAddress.ToString());
		}
	}
} 
void UMainMenu::BackToHostMenu()
{
	if (MenuSwitcher)
	{
		MenuSwitcher->SetActiveWidget(MainMenu);
	}
}



void UMainMenu::SetUp()
{
	this->AddToViewport();
	//Menu->PlayAnimation()
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(this->TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InputMode);

	PlayerController->bShowMouseCursor = true;
}

void UMainMenu::TearDown()
{
	this->RemoveFromViewport();
	//Menu->PlayAnimation()
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	FInputModeGameOnly InputMode;
	
	PlayerController->SetInputMode(InputMode);

	PlayerController->bShowMouseCursor = false;
}

void UMainMenu::OnLevelRemovedFromWorld(ULevel * InLevel, UWorld * InWorld)
{
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	FInputModeGameOnly InputModeData;

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}
