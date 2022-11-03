// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Enemy.h"



// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	SetRootComponent(boxComp);

	// 面倒贸府 1锅 规过
	//boxComp->SetGenerateOverlapEvents(true);
	//boxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//boxComp->SetCollisionObjectType(ECC_GameTraceChannel3);
	//boxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	//boxComp->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Overlap);
	
	// 面倒贸府 2锅 规过 (Preset)
	boxComp->SetGenerateOverlapEvents(true);
	boxComp->SetCollisionProfileName(TEXT("Bullet"));
	boxComp->SetBoxExtent(FVector(50, 50, 50));

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);	
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ABullet::OnMyComponentBeginOverlap);

}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector direction = GetActorForwardVector() * speed;
	FVector TargetLocation = GetActorLocation() + direction * DeltaTime;
	SetActorLocation(TargetLocation);
}

//void ABullet::NotifyActorBeginOverlap(AActor* OtherActor)
//{
	//	if (OtherActor->IsA(AEnemy::StaticClass()))
	//	{
	//		OtherActor->Destroy();
	//		this->Destroy();
	//	}
//}

void ABullet::OnMyComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("OnMyComponentBeginOverlap")));

	if (OtherActor->IsA(AEnemy::StaticClass()))
	{
		OtherActor->Destroy();
		this->Destroy();
		auto enemy = Cast<AEnemy>(OtherActor);
		enemy->Explode();
	}
}
