// Fill out your copyright notice in the Description page of Project Settings.


#include "HttpRequestActor.h"
#include "HttpModule.h"
#include "../LoginGameModeBase.h"

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

// void AHttpRequestActor::SendRequest(const FString url)
// {
// 	//������
// 	FHttpModule& httpModule = FHttpModule::Get();
// 	//FHttpModule::Get() -> ����� ������
// 
// 	TSharedPtr<IHttpRequest> req = httpModule.CreateRequest();
// 	//��⿡�� createRequest�Ͽ� ������Ʈ �ν��Ͻ��� �����Ѵ�.
// 
// 	//��û�ϱ� ���� ������ �����Ѵ�.
// 	//3������ �ʿ���.
// 	//1. set url (��û �ּ� �����ؼ� �ֱ�)
// 	req->SetURL(url); //�������� �����Ѵ�..
// 
// 	req->SetVerb(TEXT("GET"));
// 	//2. Method�� �־��ش�. (������ ���� ������ �Ŵϱ� GET!)
// 
// 	req->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
// 	//3. ���� �ְ� ���� �������� ������ Ÿ���� �����ϴ� ����.
// 	//���� �ڵ�� ������ Ÿ���� ������ ���̸�, ������ Ÿ���� json���� �ϰڴٴ� �����.
// 
// 	//��û�� �Ϸ�Ǿ��� �� ����� �Լ��� ���ε��Ѵ�.
// // 	/* req->OnProcessRequestComplete().BindUFunction(this,FName("OnReceivedData"));*/
// 	req->OnProcessRequestComplete().BindUObject(this, &AHttpRequestActor::OnReceivedData);
// 
// 	//������ ��û�� ������.
// 	req->ProcessRequest();
// 
// }
// 
// void AHttpRequestActor::OnReceivedData(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
// {
// 	UE_LOG(LogTemp, Warning, TEXT("Received Data!"));
// 
// 	if (bConnectedSuccessfully)
// 	{
// 		//�������ο� ������� ������ �Դ�.
// 		UE_LOG(LogTemp, Warning, TEXT("Received DATA!"));
// 		//��û�� �����ߴٸ� response�� �޴µ�,
// 		//content�� string���� �޾ƿ´�.
// 		FString res = Response->GetContentAsString();
// 
// 
// 		//NEW@@ res�� �׳� �Ѹ��� ���� �����ؼ� ����
// 		//FString parsedData = UJsonParseLibrary::JsonParse(res);
// 		gm->SetLogText(res);
// 	}
// 	else
// 	{
// 		gm->SetLogText("Failed Response from server...");
// 	}
// }

