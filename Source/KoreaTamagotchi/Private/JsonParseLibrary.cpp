// Fill out your copyright notice in the Description page of Project Settings.


#include "JsonParseLibrary.h"
#include "Json.h"

FString UJsonParseLibrary::JsonParse(const FString& originData)
{

	FString parsedData;

	//json �Ľ� �ϴ¹�
	//reader Ȥ�� Writer�� �����.	

	//******* reader�����
	//1. ���� �����͸� �о�� ���̱⿡ reader�� �����.
	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(originData);

	//2. reader�� �Ľ̵� ����� ���� json object�� �����Ѵ�.
	TSharedPtr<FJsonObject> result = MakeShareable(new FJsonObject());

	//3. �ص��Ѵ�.
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

	//Json ���� ���� ���� �ݴ�� ����� �ȴ�.
	 //json ���� : reader ����->jspn obj �����[�ص��� ����]->deserialize
	//********writer����� (json ����� ������ ������)
	//json���� : obj Ȥ�� value�����[�ص��� ����]  
	//�� json�� serializable�Ѵ�.

	//1. json obj�� �����ϰ� ���� �ִ´�.
	TSharedPtr<FJsonObject> jsonObj = MakeShareable(new FJsonObject()); //json ������ ���� �� �߰�ȣ�� �ִ� ����

	for (TPair<FString, FString> kv : source)
	{ //�Ű������� ���� map������ ������ ����� json ��ȣ �ȿ� �־��ִ� for��
		jsonObj->SetStringField(kv.Key, kv.Value);
	}

	//2. Writer�� �����ϰ�, json obj�� ���ڵ��Ѵ�.
	FString jsonData;

	TSharedRef<TJsonWriter<TCHAR>> writer = TJsonWriterFactory<TCHAR>::Create(&jsonData); //writer����

	//Writer�� ���� json Serialize!
	FJsonSerializer::Serialize(jsonObj.ToSharedRef(), writer);

	return jsonData;
	//totally parsing process reverse...
}
