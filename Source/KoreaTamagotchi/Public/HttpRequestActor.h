// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "HttpRequestActor.generated.h"


UCLASS()
class KOREATAMAGOTCHI_API AHttpRequestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHttpRequestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//#1. GET -> server���� ������ �޾ƿ��� �Լ�
	void SendRequest(const FString url);

	//#2. POST-> server�� ������ �����ϱ� �Լ�
	void PostRequest(const FString url);

private:
	void OnReceivedData(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);

	void OnPostData(TSharedPtr<IHttpRequest> Request, TSharedPtr<IHttpResponse>Response, bool bConnectedSuccessfully);
	
	UPROPERTY()
	class ALoginGameModeBase* gm ;

};
	