// Fill out your copyright notice in the Description page of Project Settings.


#include "JsonParseLibrary.h"
#include "Json.h"

FString UJsonParseLibrary::JsonParse(const FString& originData)
{

	FString parsedData;

	//json 파싱 하는법
	//reader 혹은 Writer를 만든다.	

	//******* reader만들기
	//1. 현재 데이터를 읽어올 것이기에 reader를 만든다.
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(originData);

	//2. reader로 파싱된 결과를 담은 json object를 선언한다.
	TSharedPtr<FJsonObject> result = MakeShareable(new FJsonObject());

	//3. 해독한다.
	if (FJsonSerializer::Deserialize(reader, result))
	{
		TArray<TSharedPtr<FJsonValue>> parseDataArr = result->GetArrayField("items");
		for (TSharedPtr<FJsonValue> pd : parseDataArr)
		{
			FString bookName = pd->AsObject()->GetStringField("bk_nm");
			FString authorName = pd->AsObject()->GetStringField("aut_nm");
			parsedData.Append(FString::Printf(TEXT("BookName : %s\nAuthor Name: %s \n\n"), *bookName, *authorName));
		}
	}

	return parsedData;
	
}


//TMap is like a dictionary and so on It do not need to Array.

FString UJsonParseLibrary::MakeJson(const TMap<FString, FString> source)
{

	//Json 분해 했을 때와 반대로 만들면 된다.
	 //json 분해 : reader 만들어서->jspn obj 만들기[해독을 위한]->deserialize
	//********writer만들기 (json 만들어 서버에 던지기)
	//json생성 : obj 혹은 value만들고[해독을 위한]  
	//그 json을 serializable한다.

	//1. json obj을 생성하고 값을 넣는다.
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject()); //json 데이터 형식 중 중괄호만 있는 상태

	for (TPair<FString, FString> kv : source)
	{ //매개변수로 받은 map형태의 데이터 덩어리를 json 괄호 안에 넣어주는 for문
		jsonObj->SetStringField(kv.Key, kv.Value);
	}

	//2. Writer를 생성하고, json obj를 인코딩한다.
	FString jsonData;

	TSharedRef<TJsonWriter<TCHAR>> writer = TJsonWriterFactory<TCHAR>::Create(&jsonData); //writer생성

	//Writer를 통해 json Serialize!
	FJsonSerializer::Serialize(jsonObj.ToSharedRef(), writer);

	return jsonData;
	//totally parsing process reverse...
}
