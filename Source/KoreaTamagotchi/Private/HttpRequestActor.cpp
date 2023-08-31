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
// 	//모듈생성
// 	FHttpModule& httpModule = FHttpModule::Get();
// 	//FHttpModule::Get() -> 모듈을 가져옴
// 
// 	TSharedPtr<IHttpRequest> req = httpModule.CreateRequest();
// 	//모듈에서 createRequest하여 리퀘스트 인스턴스를 생성한다.
// 
// 	//요청하기 위한 정보를 설정한다.
// 	//3가지가 필요함.
// 	//1. set url (요청 주소 조립해서 넣기)
// 	req->SetURL(url); //이쪽으로 접근한다..
// 
// 	req->SetVerb(TEXT("GET"));
// 	//2. Method를 넣어준다. (지금은 값을 가져올 거니까 GET!)
// 
// 	req->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
// 	//3. 내가 주고 받을 데이터의 종류와 타입을 설정하는 것임.
// 	//지금 코드는 콘텐츠 타입을 설정할 것이며, 콘텐츠 타입을 json으로 하겠다는 얘기임.
// 
// 	//요청이 완료되었을 때 실행될 함수를 바인딩한다.
// // 	/* req->OnProcessRequestComplete().BindUFunction(this,FName("OnReceivedData"));*/
// 	req->OnProcessRequestComplete().BindUObject(this, &AHttpRequestActor::OnReceivedData);
// 
// 	//서버에 요청을 보낸다.
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
// 		//성공여부에 상관없이 응답이 왔다.
// 		UE_LOG(LogTemp, Warning, TEXT("Received DATA!"));
// 		//요청이 성공했다면 response를 받는데,
// 		//content를 string으로 받아온다.
// 		FString res = Response->GetContentAsString();
// 
// 
// 		//NEW@@ res를 그냥 뿌리지 말고 분해해서 보자
// 		//FString parsedData = UJsonParseLibrary::JsonParse(res);
// 		gm->SetLogText(res);
// 	}
// 	else
// 	{
// 		gm->SetLogText("Failed Response from server...");
// 	}
// }

