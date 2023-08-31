// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Http.h"
#include "KoreaTamagotchiGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class KOREATAMAGOTCHI_API AKoreaTamagotchiGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	virtual void BeginPlay() override;

public:
	/*UFUNCTION()
	void OnResponseReceived(FHttpRequestPtr Response, bool bConnectedSucceessfully);*/
	void OnResponseReceived(FHttpRequestPtr reque, FHttpResponsePtr response, bool bConnet);
};
