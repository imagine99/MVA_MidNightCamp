// Copyright Epic Games, Inc. All Rights Reserved.


#include "KoreaTamagotchiGameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Delegates/DelegateSignatureImpl.inl"
#include "Interfaces/IHttpRequest.h"

void AKoreaTamagotchiGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AKoreaTamagotchiGameModeBase::OnResponseReceived);
	Request->SetURL("");
	Request->SetVerb("GET");
	Request->ProcessRequest();

}

void AKoreaTamagotchiGameModeBase::OnResponseReceived(FHttpRequestPtr reque, FHttpResponsePtr response, bool bConnet)
{

}

//void AKoreaTamagotchiGameModeBase::OnResponseReceived(FHttpRequestPtr Response, bool bConnectedSucceessfully)
//{
//	//UE_LOG(LogTemp, Warning, TEXT("Response %s"), *Response->GetContentAsString());
//}
