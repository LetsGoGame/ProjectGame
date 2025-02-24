// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleCharacter.h"
#include "Enemy.h"
#include "Items.h"

// Sets default values
ABattleCharacter::ABattleCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattleCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABattleCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int ABattleCharacter::Attack() 
{
	int Damage = ATK + Weapon->strength;

	TargetEnemy->GetHit(Damage);
	return Damage;
}
int ABattleCharacter::GetHit(int damage)
{
	HP -= damage - (DEF + Armor->strength);

	if (HP <= 0) 
	{
		dead_flag = true;
		HP = 0;
	}

	return HP;
}
int ABattleCharacter::Healed(int ammount_healed)
{
	HP += ammount_healed;
	if (HP > Max_HP) 
	{
		HP = Max_HP;
	}
	
	return HP;
}
int ABattleCharacter::GainEXP(int exp_gained)
{
	return 0;
}