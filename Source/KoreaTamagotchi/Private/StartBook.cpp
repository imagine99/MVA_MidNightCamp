// Fill out your copyright notice in the Description page of Project Settings.


// ��ǥ : å�� ���� ���θ����� �̵��ϰ� �ʹ�.
// 
//1. ȭ�鿡 �ִ� �ƹ����� å�� �ִ�.
// 2. ���콺�� �հ��� ������� �ٲ�� ȣ���� �� �� �ֵ����Ѵ�.
// 3. ����ڰ� Ŭ���Ѵ�.
// 4. å�� �۾�����.
// 5. �m Ŀ����. (����ƽ �޽� ��ü-> ������ å)
//6. Ŀ���鼭 ���� ĳ���Ͱ� �����ȴ�.
//7. ���θ� Ȱ��ȭ
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
//mouse hover�� �ν��ؼ� ������ ����� �ٲ��.
// ���� �ִ� å�� �������� �۾�����.
// ���� �ִ� å�� �����ȴ�.
// ���� �ִ� å�� ������ Ŀ���� (�� ������)
// ������� ĳ���Ͱ� �Բ� �����ȴ�.(��)
}

