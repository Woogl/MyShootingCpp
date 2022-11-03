// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCodingActor.generated.h"

UCLASS()
class MYSHOOTINGCPP_API AMyCodingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyCodingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION(BlueprintCallable, meta = (AllowPrivateAccess = "true"))
	int Plus(int a, int b);

	UFUNCTION(BlueprintPure, meta = (AllowPrivateAccess = "true"))
	int Minus(int a, int b);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	int number;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
	float Stamina;

};
