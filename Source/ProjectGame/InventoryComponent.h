// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item_Base.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTGAME_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

    //Functions

    UFUNCTION(BlueprintCallable, Category = "Change")
    void AddItem(FItem_Base& NewItem);

    UFUNCTION(BlueprintCallable, Category = "Change")
    bool RemoveItem(FItem_Base& ItemToRemove);

    UFUNCTION(BlueprintCallable, Category = "Change")
    TArray<FItem_Base> Sort(const FString& Type);

    UFUNCTION(BlueprintCallable, Category = "Change")
    FString GetItemName(const FItem_Base& Item);

    UFUNCTION(BlueprintCallable, Category = "Change")
    int GetItemQuantity(const FItem_Base& Item);

    UFUNCTION(BlueprintCallable, Category = "Change")
    int GetItemStrength(const FItem_Base& Item);

    UFUNCTION(BlueprintCallable, Category = "Change")
    FString GetItemType(const FItem_Base& Item);

    UFUNCTION(BlueprintCallable, Category = "Change")
    FString GetItemSubType(const FItem_Base& Item);

    //Variables

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    int money = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<FItem_Base> InventoryItems;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
