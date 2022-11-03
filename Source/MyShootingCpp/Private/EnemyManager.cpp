// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "Enemy.h"
#include "Components/ArrowComponent.h"

// Sets default values
AEnemyManager::AEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	spawnArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("spawnArrow"));
}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerHandle timerHandle;
	GetWorldTimerManager().SetTimer(timerHandle, this, &AEnemyManager::MakeEnemy, makeTime, true);
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime = currentTime + DeltaTime;

	if (currentTime >= makeTime)
	{
		GetWorld()->SpawnActor<AEnemy>(enemyToSpawn, spawnArrow->GetComponentTransform());
		currentTime = 0.f;
	}
}

void AEnemyManager::MakeEnemy()
{
	GetWorld()->SpawnActor<AEnemy>(enemyToSpawn, spawnArrow->GetComponentTransform());
}

