// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LoginGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class KOREATAMAGOTCHI_API ALoginGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, Category = MySettings)
	TSubclassOf<class ULoginWidget> httpWidget;
		
	void SetLogText(const FString msg);

public:	
	class ULoginWidget* httpUI;
};
