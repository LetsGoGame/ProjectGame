// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
class AEnemy;
class AItems;
#include "BattleCharacter.generated.h"

UCLASS()
class PROJECTGAME_API ABattleCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABattleCharacter();

	//Changing Variables
	UFUNCTION(BlueprintCallable, Category = "Change")
	int Attack();
	UFUNCTION(BlueprintCallable, Category = "Change")
	int GetHit(int damage);
	UFUNCTION(BlueprintCallable, Category = "Change")
	int Healed(int ammount_healed);
	UFUNCTION(BlueprintCallable, Category = "Change")
	int GainEXP(int exp_gained);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Varibles
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int Max_HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int ATK;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int DEF;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int SPD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int LVL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int EXP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int EXP_to_LVLUP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	AEnemy* TargetEnemy;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	AItems* Weapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	AItems* Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	AItems* Accessory;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	bool dead_flag;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
