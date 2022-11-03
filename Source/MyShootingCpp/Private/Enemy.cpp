// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "PlayerPawn.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	SetRootComponent(boxComp);

	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionProfileName(TEXT("Enemy"));
	boxComp->SetBoxExtent(FVector(50, 50, 50));

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnMyComponentBeginOverlap);

	float result = FMath::FRandRange(0.0f, 1.0f);

	if (result < 0.5f)	// 50% 확률로 플레이어 추적
	{
		auto target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		direction = target->GetActorLocation() - this->GetActorLocation();
		direction.Normalize();
	}
	else
	{
		direction = GetActorForwardVector();
	}
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + direction * speed * DeltaTime);
}

//void AEnemy::NotifyActorBeginOverlap(AActor* OtherActor)
//{
//	APlayerPawn* playerRef = Cast<APlayerPawn>(OtherActor);
//	if (playerRef)
//	{
//		OtherActor->Destroy();
//		this->Destroy();
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("NotifyActorBeginOverlap")));
//	}
//}

void AEnemy::OnMyComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor->IsA(APlayerPawn::StaticClass()))
	{
		OtherActor->Destroy();
		Explode();
		this->Destroy();
	}
}

void AEnemy::Explode()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), explosionVFX, GetActorLocation());
}
