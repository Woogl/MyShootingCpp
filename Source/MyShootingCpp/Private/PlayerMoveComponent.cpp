// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMoveComponent.h"
#include "PlayerPawn.h"

// Sets default values for this component's properties
UPlayerMoveComponent::UPlayerMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	myOwner = Cast<APlayerPawn>(GetOwner());
}


// Called every frame
void UPlayerMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// 현재 위치 (P0)
	FVector p0 = myOwner->GetActorLocation();

	// 속력 (v)
	FVector direction = myOwner->GetActorUpVector()*vertical + myOwner->GetActorRightVector()*horizontal;
	direction.Normalize();	// 단위벡터 변환
	FVector velocity = direction * speed;

	// P = P0 + v*t
	myOwner->SetActorLocation(p0 + velocity * DeltaTime);
}

void UPlayerMoveComponent::SetupInput(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &UPlayerMoveComponent::OnAxisHorizontal);
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &UPlayerMoveComponent::OnAxisVertical);

}

void UPlayerMoveComponent::OnAxisHorizontal(float Value)
{
	horizontal = Value;
}

void UPlayerMoveComponent::OnAxisVertical(float Value)
{
	vertical = Value;
}