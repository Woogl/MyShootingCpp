// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class MYSHOOTINGCPP_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 컴포넌트
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* boxComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* firePositions;

	// BP_Bullet을 담을 포인터 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ABullet> bulletFactory; // 본인이나 자식 클래스만 할당 가능

	UPROPERTY(EditAnywhere)
	class UPlayerMoveComponent* moveComp;

	UPROPERTY(EditAnywhere)
	class UPlayerFireComponent* fireComp;

	UPROPERTY(EditAnywhere)
	class USoundBase* fireSound;
};
