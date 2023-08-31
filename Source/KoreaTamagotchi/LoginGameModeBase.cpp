// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginGameModeBase.h"
#include "LoginWidget.h"
#include "Components/TextBlock.h"

void ALoginGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	httpUI = CreateWidget<ULoginWidget>(GetWorld(), httpWidget);

	if (httpUI != nullptr)
	{
		httpUI->AddToViewport();
	}
	
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());


}

//로그 출력 함수
void ALoginGameModeBase::SetLogText(const FString msg)
{
	if (httpUI != nullptr)
	{
		httpUI->text_log->SetText(FText::FromString(msg));
	}
}
