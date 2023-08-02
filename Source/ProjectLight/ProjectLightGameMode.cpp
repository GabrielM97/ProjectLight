// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectLightGameMode.h"
#include "ProjectLightCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectLightGameMode::AProjectLightGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
