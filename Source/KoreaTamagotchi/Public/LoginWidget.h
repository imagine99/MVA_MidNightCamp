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

	/*-------------- ID ------------------*/
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_ID;
	
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UEditableText* editable_ID;
	
	/*-------------- PW ------------------*/
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UTextBlock* text_PW;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UEditableText* editable_PW;
	
	/*---------- Login BTN -----------*/
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UButton* btn_Login;
	
	/*--------IMAGE-------*/
	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = MySettings)
	class UImage* Img_Login;




	/*----------------------------------FUNCTION----------*/
	UFUNCTION()
	void SendLogin();
};
