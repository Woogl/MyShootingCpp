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

	// ���� target�� nullptr�̶��
	if (target == nullptr)
	{
		// target�� �÷��̾ �ִ´�
		target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); // const UObject * WorldContextObject�� �� �ʿ��Ѱ���?
	}
}

// Called every frame
void ATail::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ��ư��鼭 �������� ���ϴ� ������ ���ϰ� �̵��ϰ� �ʹ�.
	FVector direction = target->GetActorLocation() - this->GetActorLocation();
	direction.Normalize(); // BP������ ���͸� ��ȯ�ϴµ� C++�� ��� �� bool�� ��ȯ��?
	SetActorLocation(GetActorLocation() + direction * speed * DeltaTime);

}

