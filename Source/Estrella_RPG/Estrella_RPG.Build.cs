// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Estrella_RPG : ModuleRules
{
	public Estrella_RPG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "GameplayAbilities", "GameplayTags", "GameplayTasks" });
		
	}


}
