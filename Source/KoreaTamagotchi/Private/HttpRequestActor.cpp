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
	//모듈생성
	FHttpModule& httpModule = FHttpModule::Get();
	//FHttpModule::Get() -> 모듈을 가져옴

	TSharedPtr<IHttpRequest> req = httpModule.CreateRequest();
	//모듈에서 createRequest하여 리퀘스트 인스턴스를 생성한다.

	//요청하기 위한 정보를 설정한다.
	//3가지가 필요함.
	//1. set url (요청 주소 조립해서 넣기)
	req->SetURL(url); //이쪽으로 접근한다..

	req->SetVerb(TEXT("GET"));
	//2. Method를 넣어준다. (지금은 값을 가져올 거니까 GET!)

	req->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	//3. 내가 주고 받을 데이터의 종류와 타입을 설정하는 것임.
	//지금 코드는 콘텐츠 타입을 설정할 것이며, 콘텐츠 타입을 json으로 하겠다는 얘기임.

	//요청이 완료되었을 때 실행될 함수를 바인딩한다.
// 	/* req->OnProcessRequestComplete().BindUFunction(this,FName("OnReceivedData"));*/
	req->OnProcessRequestComplete().BindUObject(this, &AHttpRequestActor::OnReceivedData);

	//서버에 요청을 보낸다.
	req->ProcessRequest();

}

void AHttpRequestActor::OnReceivedData(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	UE_LOG(LogTemp, Warning, TEXT("Received Data!"));

	if (bConnectedSuccessfully)
	{
		//성공여부에 상관없이 응답이 왔다.
		UE_LOG(LogTemp, Warning, TEXT("Received DATA!"));
		//요청이 성공했다면 response를 받는데,
		//content를 string으로 받아온다.
		FString res = Response->GetContentAsString();


		//NEW@@ res를 그냥 뿌리지 말고 분해해서 보자
		//FString parsedData = UJsonParseLibrary::JsonParse(res);
		gm->SetLogText(res);
	}
	else
	{
		gm->SetLogText("Failed Response from server...");
	}
}


/*---------------------- POST ---------------------------*/
	//POST 메소드 요청하기
void AHttpRequestActor::PostRequest(const FString url)
{
	//server에 데이터를 줄건데, 
	//json으로 만들어서 데이터를 넘겨줄 때를 위해
	//JsonParse.h에서 서버에게 넘겨줄 데이터를 만들 것임.
	TMap<FString, FString> clientData;
	clientData.Add("id", "qwer");
	clientData.Add("password", "qwer");

	FString myJsonData = UJsonParseLibrary::MakeJson(clientData);
	/*gm->SetLogText(myJsonData);*/

	class FHttpModule& httpModule = FHttpModule::Get();
	//요청설정
	TSharedRef<IHttpRequest> req = httpModule.CreateRequest();
	req->SetURL(url);
	req->SetVerb(TEXT("POST"));
	req->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	//get이라면 여기서 끝이지만, POST일 경우에는 게시할 데이터를 줘야함.
	//SET CONTENT를 통해 넘길 컨텐츠 값을 주면 됨.
	//set contentAsString은 넘길 컨텐츠가 스트링이면 스트링 그대로 가도록 설정해주는 함수임.
	req->SetContentAsString(myJsonData);

	req->OnProcessRequestComplete().BindUObject(this, &AHttpRequestActor::OnPostData);

	req->ProcessRequest(); // 데이터 날리기
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


		//request에서는 문제가 없었나..?
		//요청 전송 상태 확인
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

		//응답 코드 확인
		int32 responseCode = Response->GetResponseCode();
		gm->SetLogText(FString::Printf(TEXT("Response Code : %d"), responseCode));
		
	}
}

