// Copyright Epic Games, Inc. All Rights Reserved.


#include "KoreaTamagotchiGameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Delegates/DelegateSignatureImpl.inl"
#include <ImageDownload/Public/WebImage.h>
#include "Interfaces/IHttpRequest.h"

void AKoreaTamagotchiGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &AKoreaTamagotchiGameModeBase::OnResponseReceived,);
	Request->SetURL("");
	Request->SetVerb("GET");
	Request->ProcessRequest();

}

void AKoreaTamagotchiGameModeBase::OnResponseReceived(FHttpRequestPtr Response, bool bConnectedSucceessfully)
{
	//UE_LOG(LogTemp, Warning, TEXT("Response %s"), *Response->GetContentAsString());
}
