// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory_Base.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AInventory_Base::AInventory_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AInventory_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventory_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// My functions
void AInventory_Base::AddItems(AItems* new_item)
{
	bool found = false;
	for (int i = 0; i < CurrInventory.Num(); i++) 
	{
		if (CurrInventory[i]->name == new_item->name) {
			CurrInventory[i]->quantity++;
			found = true;
		}
	}

	if (found == false)
	{
		new_item->quantity = 1;
		CurrInventory.Add(new_item);
	}

}

bool AInventory_Base::RemoveItem(AItems* rem_item)
{
	bool found = false;
	for (int i = 0; i < CurrInventory.Num(); i++)
	{
		if (CurrInventory[i]->name == rem_item->name) {
			CurrInventory[i]->quantity--;
			found = true;
			if (CurrInventory[i]->quantity <= 0) {
				const AItems* temp = CurrInventory[i];
				CurrInventory.RemoveAt(i, 1, true);
			}
		}
	}

	return found;
}

TArray<AItems*> AInventory_Base::Sort(FString type)
{
	TArray<AItems*> sorted_list;

	for (int i = 0; i < CurrInventory.Num(); i++)
	{
		if (CurrInventory[i]->type == type) {
			sorted_list.Add(CurrInventory[i]);
		}
	}

	return sorted_list;
}

FString AInventory_Base::GetName(AItems* item) 
{
	return item->name;
}

int AInventory_Base::GetQuantity(AItems* item)
{
	return item->quantity;
}