// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DriveVisionPawn.h"
#include "DriveVisionSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class DRIVEVISION_API ADriveVisionSportsCar : public ADriveVisionPawn
{
	GENERATED_BODY()
	
public:

	ADriveVisionSportsCar();
};
