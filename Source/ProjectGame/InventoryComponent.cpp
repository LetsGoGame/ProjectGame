// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::AddItem(FItem_Base& new_item)
{
	bool found = false;
	for (int i = 0; i < InventoryItems.Num(); i++)
	{
		if (InventoryItems[i].name == new_item.name) {
			InventoryItems[i].quantity++;
			found = true;
		}
	}

	if (found == false)
	{
		new_item.quantity = 1;
		InventoryItems.Add(new_item);
	}

}

bool UInventoryComponent::RemoveItem(FItem_Base& rem_item)
{
	bool found = false;
	for (int i = 0; i < InventoryItems.Num(); i++)
	{
		if (InventoryItems[i].name == rem_item.name) {
			InventoryItems[i].quantity--;
			found = true;
			if (InventoryItems[i].quantity <= 0) {
				FItem_Base temp = InventoryItems[i];
				InventoryItems.RemoveAt(i, 1, true);
			}
		}
	}

	return found;
}

TArray<FItem_Base> UInventoryComponent::Sort(const FString& type)
{
	TArray<FItem_Base> sorted_list;

	for (int i = 0; i < InventoryItems.Num(); i++)
	{
		if (InventoryItems[i].type == type) {
			sorted_list.Add(InventoryItems[i]);
		}
	}

	return sorted_list;
}

FString UInventoryComponent::GetItemName(const FItem_Base& item)
{
	return item.name;
}

int UInventoryComponent::GetItemQuantity(const FItem_Base& item)
{
	return item.quantity;
}

int UInventoryComponent::GetItemStrength(const FItem_Base& item)
{
	return item.strength;
}

FString UInventoryComponent::GetItemType(const FItem_Base& item)
{
	return item.type;
}

FString UInventoryComponent::GetItemSubType(const FItem_Base& item)
{
	return item.sub_type;
}