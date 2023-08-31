// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JsonParseLibrary.generated.h"

/**
 * 
 */
UCLASS()
class KOREATAMAGOTCHI_API UJsonParseLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static FString JsonParse(const FString& originData);

	//post데이터를 만들기 위한 함수
	//key와 value가 많이 필요함->map자료형 배열을 변수로 받는다.
	static FString MakeJson(const TMap<FString, FString> source);


	
};
