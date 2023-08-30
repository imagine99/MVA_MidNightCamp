// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "jsonWidget.generated.h"

/**
 * 
 */
UCLASS()
class KOREATAMAGOTCHI_API UjsonWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, Meta=(BindWidget), Category = MySettings)
	class UEditableText* edit_page;
	
	UPROPERTY(VisibleAnywhere, Meta=(BindWidget), Category = MySettings)
	class UButton* btn_send;

	UPROPERTY(VisibleAnywhere, Meta=(BindWidget), Category = MySettings)
	class UTextBlock* text_log;

private:
	UFUNCTION()
	void SendRequest();
};
