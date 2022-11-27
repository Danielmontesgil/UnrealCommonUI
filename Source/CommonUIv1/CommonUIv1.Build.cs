// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CommonUIv1 : ModuleRules
{
	public CommonUIv1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara", "UMG" });
    }
}
