// Fill out your copyright notice in the Description page of Project Settings.


#include "Tail.h"
#include "PlayerPawn.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
ATail::ATail()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATail::BeginPlay()
{
	Super::BeginPlay();

	// 만약 target이 nullptr이라면
	if (target == nullptr)
	{
		// target에 플레이어를 넣는다
		target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); // const UObject * WorldContextObject가 왜 필요한거지?
	}
}

// Called every frame
void ATail::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 살아가면서 목적지를 향하는 방향을 구하고 이동하고 싶다.
	FVector direction = target->GetActorLocation() - this->GetActorLocation();
	direction.Normalize(); // BP에서는 벡터를 반환하는데 C++의 요건 왜 bool을 반환함?
	SetActorLocation(GetActorLocation() + direction * speed * DeltaTime);

}

