// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DriveVision : ModuleRules
{
	public DriveVision(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] { "OpenCVHelper", "OpenCV" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "ChaosVehicles", "PhysicsCore" });
	}
}
