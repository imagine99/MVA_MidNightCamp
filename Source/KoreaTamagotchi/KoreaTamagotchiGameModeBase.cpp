// Copyright Epic Games, Inc. All Rights Reserved.


#include "KoreaTamagotchiGameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Delegates/DelegateSignatureImpl.inl"
#include "Interfaces/IHttpRequest.h"
#include <Blueprint/UserWidget.h>
#include "jsonWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void AKoreaTamagotchiGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	// 유튜브보고 한거	
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();

	TSharedRef<FJsonObject> RequestObj = MakeShared<FJsonObject>();
	RequestObj->SetStringField("id", "qwerr");
	RequestObj->SetStringField("password", "qwerr");

	FString RequestBody;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
	FJsonSerializer::Serialize(RequestObj, Writer);

	Request->OnProcessRequestComplete().BindUObject(this, &AKoreaTamagotchiGameModeBase::OnResponseReceived);
	Request->SetURL("http://192.168.1.71:9000/maha/signup");
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(RequestBody);
	Request->ProcessRequest();

	
	
	/*httpUI = CreateWidget<UjsonWidget>(GetWorld(), jsonWidget);
	if (httpUI != nullptr)
	{
		httpUI->AddToViewport();
	}*/

	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());




}

void AKoreaTamagotchiGameModeBase::OnResponseReceived(FHttpRequestPtr reque, FHttpResponsePtr response, bool bConnet)
{
	TSharedPtr<FJsonObject> Responseobj;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(response->GetContentAsString());
	FJsonSerializer::Deserialize(Reader, Responseobj);

	UE_LOG(LogTemp, Display, TEXT("Response %s"), *response->GetContentAsString());
	UE_LOG(LogTemp, Display, TEXT("id: %s"), *Responseobj->GetStringField("id"));
	UE_LOG(LogTemp, Display, TEXT("password: %s"), *Responseobj->GetStringField("password"));
}

//void AKoreaTamagotchiGameModeBase::OnResponseReceived(FHttpRequestPtr Response, bool bConnectedSucceessfully)
//{
//}
