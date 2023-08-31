// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableText.h"
#include "EngineUtils.h"
#include "HttpRequestActor.h"

void ULoginWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Button Send Login Widget Bind.
	btn_Login->OnClicked.AddDynamic(this,&ULoginWidget::PostRequest);

	for (TActorIterator<AHttpRequestActor> it(GetWorld()); it; ++it)
	{
		httpReqActor = *it;
	}
}

void ULoginWidget::SendLogin()
{
	if (!edit_ID->GetText().IsEmpty() && !edit_PW->GetText().IsEmpty())
	{
		FString fullURL;

		/*fullURL = FString::Printf(TEXT("%s?id=%s&password=%s"), *baseURL,*edit_id->GetText().ToString(), *edit_pw->GetText().ToString());*/
		fullURL = FString::Printf(TEXT("%s?id=%s&password=%s"), *baseURL, *edit_ID->GetText().ToString(), *edit_PW->GetText().ToString());
		//httpReqActor->SendRequest(fullURL);
		UE_LOG(LogTemp, Warning, TEXT("Send Request!"));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *fullURL);
	}
 }

void ULoginWidget::PostRequest()
{
	if (httpReqActor != nullptr)
	{
		/*httpReqActor->PostRequest(baseURL);*/
		id = edit_ID->GetText().ToString();
		password = edit_PW->GetText().ToString();
		FString fullPath = baseURL;
		httpReqActor->PostRequest(fullPath);
	}
}
