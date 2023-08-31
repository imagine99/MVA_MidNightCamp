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
	void OnResponseReceived(FHttpRequestPtr reque, FHttpResponsePtr response, bool bConnet);
	//void OnResponseReceived(FHttpRequestPtr Response, bool bConnectedSucceessfully);*/


	UPROPERTY(EditAnywhere, Category=MySettings)
	TSubclassOf<class UjsonWidget> jsonWidget;

	void SetLogText(const FString msg);
	void SetImageTexture(class UTexture2D* tex);

private:
	class UHttpWidget* httpUI;
};
