// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory_Base.h"

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
		if (CurrInventory[i].ItemName == new_item->name) {
			CurrInventory[i].Quantity++;
			found = true;
		}
	}

	if (found == false)
	{
		CurrInventory.Add(FInventoryItem(new_item->name, new_item, 1));
	}

}

bool AInventory_Base::RemoveItem(AItems* rem_item)
{
	bool found = false;
	for (int i = 0; i < CurrInventory.Num(); i++)
	{
		if (CurrInventory[i].ItemName == rem_item->name) {
			CurrInventory[i].Quantity--;
			found = true;
			if (CurrInventory[i].Quantity <= 0) {
				const FInventoryItem temp = CurrInventory[i];
				CurrInventory.RemoveAt(i, 1, true);
			}
		}
	}

	return found;
}

TArray<FInventoryItem> AInventory_Base::Sort(FString type)
{
	TArray<FInventoryItem> sorted_list;

	for (int i = 0; i < CurrInventory.Num(); i++)
	{
		if (CurrInventory[i].ItemRef->type == type) {
			sorted_list.Add(CurrInventory[i]);
		}
	}

	return sorted_list;
}