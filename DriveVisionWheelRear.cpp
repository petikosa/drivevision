// Copyright Epic Games, Inc. All Rights Reserved.

#include "DriveVisionWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UDriveVisionWheelRear::UDriveVisionWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}