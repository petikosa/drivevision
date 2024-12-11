// Copyright Epic Games, Inc. All Rights Reserved.

#include "DriveVisionWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UDriveVisionWheelFront::UDriveVisionWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}