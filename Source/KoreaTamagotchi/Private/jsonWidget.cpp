// Fill out your copyright notice in the Description page of Project Settings.


#include "jsonWidget.h"
#include "Components/Button.h"
#include "Components/EditableText.h"

void UjsonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	btn_send->OnClicked.AddDynamic(this, &UjsonWidget::SendRequest);

	
}

void UjsonWidget::SendRequest()
{

}
