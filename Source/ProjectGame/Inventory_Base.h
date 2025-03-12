#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item_Base.h" // Include the struct header
#include "Inventory_Base.generated.h"

UCLASS(Blueprintable)
class PROJECTGAME_API AInventory_Base : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AInventory_Base();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    int money = 0;

    UFUNCTION(BlueprintCallable, Category = "Change")
    void AddItem(FItem_Base& NewItem);

    UFUNCTION(BlueprintCallable, Category = "Change")
    bool RemoveItem(FItem_Base& ItemToRemove);

    UFUNCTION(BlueprintCallable, Category = "Change")
    TArray<FItem_Base> Sort(const FString& Type);

    UFUNCTION(BlueprintCallable, Category = "Change")
    FString GetItemName(const FItem_Base& Item) const;

    UFUNCTION(BlueprintCallable, Category = "Change")
    int GetItemQuantity(const FItem_Base& Item) const;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<FItem_Base> CurrInventory;

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
};
