// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include <Components/ArrowComponent.h>
#include "Bullet.h"
#include "PlayerMoveComponent.h"
#include "PlayerFireComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트 생성
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	SetRootComponent(boxComp);

	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionProfileName(TEXT("Player"));

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);

	firePositions = CreateDefaultSubobject<UArrowComponent>(TEXT("firePosition"));
	firePositions->SetRelativeLocation(FVector(0, 0, 100));
	firePositions->SetRelativeRotation(FRotator(90, 0, 0)); // Pitch, Yaw, Roll
	firePositions->SetupAttachment(meshComp);

	moveComp = CreateDefaultSubobject<UPlayerMoveComponent>(TEXT("moveComp"));
	fireComp = CreateDefaultSubobject<UPlayerFireComponent>(TEXT("fireComp"));

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	moveComp->SetupInput(PlayerInputComponent);
	fireComp->SetupInput(PlayerInputComponent);
}


