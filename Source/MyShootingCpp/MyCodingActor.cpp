// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCodingActor.h"

// Sets default values
AMyCodingActor::AMyCodingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AMyCodingActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Add: 0부터 4까지 원소 넣기"));
	TArray<int> IntArr;
	for (int i = 0; i < 5; i++)
	{
		IntArr.Add(i);
		UE_LOG(LogTemp, Warning, TEXT("%d"), IntArr[i]);
	}

	UE_LOG(LogTemp, Warning, TEXT("Remove: 원소 3 제거"));
	IntArr.Remove(3);
	for (int i = 0; i < IntArr.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d"), IntArr[i]);
	}

	UE_LOG(LogTemp, Warning, TEXT("Insert: index 1에 8 넣기"));
	IntArr.Insert(8, 1);
	for (int i = 0; i < IntArr.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d"), IntArr[i]);
	}

	UE_LOG(LogTemp, Warning, TEXT("Find: 원소 8 찾기"));
	int IndexEight = IntArr.Find(8);
	UE_LOG(LogTemp, Warning, TEXT("%d"), IndexEight);

	UE_LOG(LogTemp, Warning, TEXT("Sort: 정렬"));
	IntArr.Sort();
	for (int i = 0; i < IntArr.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d"), IntArr[i]);
	}
}

int AMyCodingActor::Plus(int a, int b)
{
	return a + b;
}

int AMyCodingActor::Minus(int a, int b)
{
	return a - b;
}

// Called every frame
void AMyCodingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (number == 0)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("안녕"));
	//}
	//else if (number >= 1 && number <= 3)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Hello"));
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Bye"));
	//}

}