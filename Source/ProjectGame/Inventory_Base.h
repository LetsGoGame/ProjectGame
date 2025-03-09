// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items.h"
#include "GameFramework/Actor.h"
#include "Inventory_Base.generated.h"

// Move FInventoryItem ABOVE AInventory_Base
//USTRUCT(BlueprintType)
//struct FInventoryItem
//{
//    GENERATED_BODY()
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
//    FString ItemName;
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
//    AItems* ItemRef;
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
//    int32 Quantity;
//
//    // Default constructor
//    FInventoryItem() : ItemName(TEXT("")), ItemRef(nullptr), Quantity(0) {}
//
//    // Constructor for easy initialization
//    FInventoryItem(FString Name, AItems* Item, int32 Qty)
//        : ItemName(Name), ItemRef(Item), Quantity(Qty) {
//    }
//};

UCLASS(Blueprintable)
class PROJECTGAME_API AInventory_Base : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AInventory_Base();

    UFUNCTION(BlueprintCallable, Category = "Change")
    void AddItems(AItems* new_item);

    UFUNCTION(BlueprintCallable, Category = "Change")
    bool RemoveItem(AItems* rem_item);

    UFUNCTION(BlueprintCallable, Category = "Change")
    TArray<AItems*> Sort(FString type);

    UFUNCTION(BlueprintCallable, Category = "Change")
    FString GetName(int index);

    UFUNCTION(BlueprintCallable, Category = "Change")
    int GetQuantity(int index);

    // Now this is correctly placed AFTER FInventoryItem is defined
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<AItems*> CurrInventory;

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
};
