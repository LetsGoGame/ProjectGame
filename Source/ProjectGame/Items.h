// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

UCLASS()
class PROJECTGAME_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItems();

	UFUNCTION(BlueprintNativeEvent, Category="Functions")
	void GetUsed();

	//Variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Property")
	FString type = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	FString sub_type = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	int strength = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	FString name = "";

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
