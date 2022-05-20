// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PvZ : ModuleRules
{
	public PvZ(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "UMG", "Paper2D"} );
		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
