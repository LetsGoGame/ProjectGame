#pragma once

#include "CoreMinimal.h"
#include "Item_Base.generated.h"

USTRUCT(BlueprintType) // Enables Blueprint support
struct FItem_Base
{
    GENERATED_BODY()

public:
    // Expose variables to Blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	FString type = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	FString sub_type = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	int strength = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	FString name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Property")
	int quantity = 0;

    // Default constructor
	FItem_Base()
		: name(TEXT("Default")), type("type"), sub_type("sub"), strength(5), quantity(7) {};
};

USTRUCT(BlueprintType)
struct FWeaponItem : public FItem_Base
{
	GENERATED_BODY()

public:

	// Default constructor (must call parent constructor)
	FWeaponItem()
		: FItem_Base()
	{
		type = "Weapon";
	};
};

USTRUCT(BlueprintType)
struct FArmorItem : public FItem_Base
{
	GENERATED_BODY()

public:

	// Default constructor (must call parent constructor)
	FArmorItem()
		: FItem_Base()
	{
		type = "Armor";
	};
};

USTRUCT(BlueprintType)
struct FConsumeItem : public FItem_Base
{
	GENERATED_BODY()

public:

	// Default constructor (must call parent constructor)
	FConsumeItem()
		: FItem_Base()
	{
		type = "Consumable";
	};
};

USTRUCT(BlueprintType)
struct FAccessItem : public FItem_Base
{
	GENERATED_BODY()

public:

	// Default constructor (must call parent constructor)
	FAccessItem()
		: FItem_Base()
	{
		type = "Accessory";
	};
};