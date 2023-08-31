// Fill out your copyright notice in the Description page of Project Settings.


// 목표 : 책을 눌러 메인맵으로 이동하고 싶다.
// 
//1. 화면에 있는 훈민정음 책이 있다.
// 2. 마우스가 손가락 모양으로 바뀌어 호버가 될 수 있도록한다.
// 3. 사용자가 클릭한다.
// 4. 책이 작아진다.
// 5. 퐉 커진다. (스태틱 메쉬 교체-> 펼쳐진 책)
//6. 커지면서 개인 캐릭터가 스폰된다.
//7. 메인맵 활성화
#include "StartBook.h"
#include "Components/BoxComponent.h"

// Sets default values
AStartBook::AStartBook()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	compBox = CreateDefaultSubobject<UBoxComponent>(TEXT("compBox"));
	SetRootComponent(compBox);
	compBox->SetRelativeScale3D(FVector(50));
	compMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("compMesh"));
	compMesh->SetupAttachment(compBox);
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Script/Engine.StaticMesh'/Game/LHJ/Resource/BOOK.BOOK'"));

	if (tempMesh.Succeeded())
	{
		compMesh->SetStaticMesh(tempMesh.Object);
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("omg static mesh error!"));
	}
}

// Called when the game starts or when spawned
void AStartBook::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStartBook::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Mouse left Click -> Game Start
void AStartBook::GameStart()
{
//mouse hover를 인식해서 포인터 모양이 바뀐다.
// 닫혀 있는 책의 스케일이 작아진다.
// 열려 있는 책이 스폰된다.
// 열려 있는 책이 빠르게 커지며 (펑 터지듯)
// 사용자의 캐릭터가 함께 스폰된다.(뿅)
}

