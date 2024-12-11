// Copyright Epic Games, Inc. All Rights Reserved.

#include "DriveVisionGameMode.h"
#include "DriveVisionPlayerController.h"

ADriveVisionGameMode::ADriveVisionGameMode()
{
	PlayerControllerClass = ADriveVisionPlayerController::StaticClass();
}
