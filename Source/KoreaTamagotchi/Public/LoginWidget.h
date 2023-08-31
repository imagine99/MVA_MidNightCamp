// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginWidget.generated.h"

/**
 * 
 */
UCLASS()
class KOREATAMAGOTCHI_API ULoginWidget : public UUserWidget
{
	GENERATED_BODY()


protected:
	virtual void NativeConstruct() override;

public:
	/*-------------- ID ------------------*/
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_ID;
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UEditableText* edit_ID;
	
	/*-------------- PW ------------------*/
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_PW;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UEditableText* edit_PW;
	
	/*---------- Login BTN -----------*/
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UButton* btn_Login;
	
	/*--------IMAGE-------*/
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UImage* Img_Login;

	/*---------LOG----------*/
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_log;


	UPROPERTY()
	class AHttpRequestActor* httpReqActor;
	
	//있는 id로 접속 할 수 있는 [post]
	FString baseURL = "http://172.16.16.178:9000/maha/login";
	

	/*----------------------------------FUNCTION----------*/
	UFUNCTION()
	void SendLogin();
	UFUNCTION()
	void PostRequest();

public:
	FString id = "qwer";
	FString password = "qwer";

};
