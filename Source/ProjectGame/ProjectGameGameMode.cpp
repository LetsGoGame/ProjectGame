// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectGameGameMode.h"
#include "ProjectGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectGameGameMode::AProjectGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
