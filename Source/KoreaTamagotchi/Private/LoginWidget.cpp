// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableText.h"

void ULoginWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Button Send Login Widget Bind.
	btn_Login->OnClicked.AddDynamic(this,&ULoginWidget::SendLogin);

	
 //login session을 웹서버에 보낼 것이다.
}

void ULoginWidget::SendLogin()
{
	
}
