// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
class ABattleCharacter;
#include "Enemy.generated.h"

UCLASS()
class PROJECTGAME_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

	UFUNCTION(BlueprintCallable, Category = "Change")
	int Attack();
	UFUNCTION(BlueprintCallable, Category = "Change")
	int GetHit(int Damage);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Varibles
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int ATK;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int DEF;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int SPD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	ABattleCharacter* TargetCharacter;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
