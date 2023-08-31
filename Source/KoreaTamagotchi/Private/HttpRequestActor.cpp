// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpRequestActor.h"
#include "HttpModule.h"
#include "../LoginGameModeBase.h"
#include "JsonParseLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AHttpRequestActor::AHttpRequestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHttpRequestActor::BeginPlay()
{
	Super::BeginPlay();
	gm = GetWorld()->GetAuthGameMode<ALoginGameModeBase>();
}

// Called every frame
void AHttpRequestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHttpRequestActor::SendRequest(const FString url)
{
	//������
	FHttpModule& httpModule = FHttpModule::Get();
	//FHttpModule::Get() -> ����� ������

	TSharedPtr<IHttpRequest> req = httpModule.CreateRequest();
	//��⿡�� createRequest�Ͽ� ������Ʈ �ν��Ͻ��� �����Ѵ�.

	//��û�ϱ� ���� ������ �����Ѵ�.
	//3������ �ʿ���.
	//1. set url (��û �ּ� �����ؼ� �ֱ�)
	req->SetURL(url); //�������� �����Ѵ�..

	req->SetVerb(TEXT("GET"));
	//2. Method�� �־��ش�. (������ ���� ������ �Ŵϱ� GET!)

	req->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	//3. ���� �ְ� ���� �������� ������ Ÿ���� �����ϴ� ����.
	//���� �ڵ�� ������ Ÿ���� ������ ���̸�, ������ Ÿ���� json���� �ϰڴٴ� �����.

	//��û�� �Ϸ�Ǿ��� �� ����� �Լ��� ���ε��Ѵ�.
// 	/* req->OnProcessRequestComplete().BindUFunction(this,FName("OnReceivedData"));*/
	req->OnProcessRequestComplete().BindUObject(this, &AHttpRequestActor::OnReceivedData);

	//������ ��û�� ������.
	req->ProcessRequest();

}

void AHttpRequestActor::OnReceivedData(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	UE_LOG(LogTemp, Warning, TEXT("Received Data!"));

	if (bConnectedSuccessfully)
	{
		//�������ο� ������� ������ �Դ�.
		UE_LOG(LogTemp, Warning, TEXT("Received DATA!"));
		//��û�� �����ߴٸ� response�� �޴µ�,
		//content�� string���� �޾ƿ´�.
		FString res = Response->GetContentAsString();


		//NEW@@ res�� �׳� �Ѹ��� ���� �����ؼ� ����
		//FString parsedData = UJsonParseLibrary::JsonParse(res);
		gm->SetLogText(res);
	}
	else
	{
		gm->SetLogText("Failed Response from server...");
	}
}


/*---------------------- POST ---------------------------*/
	//POST �޼ҵ� ��û�ϱ�
void AHttpRequestActor::PostRequest(const FString url)
{
	//server�� �����͸� �ٰǵ�, 
	//json���� ���� �����͸� �Ѱ��� ���� ����
	//JsonParse.h���� �������� �Ѱ��� �����͸� ���� ����.
	TMap<FString, FString> clientData;
	clientData.Add("id", "qwer");
	clientData.Add("password", "qwer");

	FString myJsonData = UJsonParseLibrary::MakeJson(clientData);
	/*gm->SetLogText(myJsonData);*/

	class FHttpModule& httpModule = FHttpModule::Get();
	//��û����
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();
	req->SetURL(url);
	req->SetVerb(TEXT("POST"));
	req->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	//get�̶�� ���⼭ ��������, POST�� ��쿡�� �Խ��� �����͸� �����.
	//SET CONTENT�� ���� �ѱ� ������ ���� �ָ� ��.
	//set contentAsString�� �ѱ� �������� ��Ʈ���̸� ��Ʈ�� �״�� ������ �������ִ� �Լ���.
	req->SetContentAsString(myJsonData);

	req->OnProcessRequestComplete().BindUObject(this, &AHttpRequestActor::OnPostData);

	req->ProcessRequest(); // ������ ������
}

void AHttpRequestActor::OnPostData(TSharedPtr<IHttpRequest> Request, TSharedPtr<IHttpResponse>Response, bool bConnectedSuccessfully)
{
	if (bConnectedSuccessfully)
	{
		FString receivedData = Response->GetContentAsString();
		gm->SetLogText(receivedData);
		EHttpRequestStatus::Type status = Request->GetStatus();
		
	
		/*UE_LOG(LogTemp, Warning, TEXT("Received success!\n result = %d"),status);*/
		if (status == 4)	//Login success.
		{
			UGameplayStatics::OpenLevel(this, TEXT("OpeningMap"),false);
		}
	}
	else
	{


		//request������ ������ ������..?
		//��û ���� ���� Ȯ��
		EHttpRequestStatus::Type status = Request->GetStatus();
		switch (status)
		{
		case EHttpRequestStatus::NotStarted:
			break;
		case EHttpRequestStatus::Processing:
			break;
		case EHttpRequestStatus::Failed:
			break;
		case EHttpRequestStatus::Failed_ConnectionError:
			break;
		case EHttpRequestStatus::Succeeded:
			break;
		default:
			break;
		}

		//���� �ڵ� Ȯ��
		int32 responseCode = Response->GetResponseCode();
		gm->SetLogText(FString::Printf(TEXT("Response Code : %d"), responseCode));
		
	}
}

