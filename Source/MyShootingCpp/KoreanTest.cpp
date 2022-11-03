// Fill out your copyright notice in the Description page of Project Settings.


#include "KoreanTest.h"

// Sets default values
AKoreanTest::AKoreanTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKoreanTest::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("00"));
}

// Called every frame
void AKoreanTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

