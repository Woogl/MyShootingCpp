// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFireComponent.h"
#include "Bullet.h"
#include <Components/ActorComponent.h>
#include <Components/ArrowComponent.h>
#include "PlayerPawn.h"
#include <Kismet/GameplayStatics.h>


// Sets default values for this component's properties
UPlayerFireComponent::UPlayerFireComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UPlayerFireComponent::BeginPlay()
{
	Super::BeginPlay();

	myOwner = Cast<APlayerPawn>(GetOwner());
	
}


// Called every frame
void UPlayerFireComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerFireComponent::SetupInput(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &UPlayerFireComponent::OnActionFire);

}

void UPlayerFireComponent::OnActionFire()
{
	GetWorld()->SpawnActor<ABullet>(myOwner->bulletFactory, myOwner->firePositions->GetComponentTransform());

	UGameplayStatics::PlaySound2D(GetWorld(), myOwner->fireSound);
}