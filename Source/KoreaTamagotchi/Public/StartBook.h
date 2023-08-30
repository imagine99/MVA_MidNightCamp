// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StartBook.generated.h"

UCLASS()
class KOREATAMAGOTCHI_API AStartBook : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStartBook();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public :
	UPROPERTY(EditAnywhere)
	class UBoxComponent* compBox;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UStaticMeshComponent* compMesh;

/*---------------- FUNCTION -----------------*/
public:
	UFUNCTION()
	void GameStart();

};
