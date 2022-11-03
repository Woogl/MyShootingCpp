// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManager.generated.h"

UCLASS()
class MYSHOOTINGCPP_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
	class UArrowComponent* spawnArrow;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
	TSubclassOf<class AEnemy> enemyToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Info")
	float makeTime = 2.0f;

	float currentTime;

	void MakeEnemy();
};
