// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UC_Spatial_Inventory : ModuleRules
{
	public UC_Spatial_Inventory(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"UC_Spatial_Inventory",
			"UC_Spatial_Inventory/Variant_Platforming",
			"UC_Spatial_Inventory/Variant_Platforming/Animation",
			"UC_Spatial_Inventory/Variant_Combat",
			"UC_Spatial_Inventory/Variant_Combat/AI",
			"UC_Spatial_Inventory/Variant_Combat/Animation",
			"UC_Spatial_Inventory/Variant_Combat/Gameplay",
			"UC_Spatial_Inventory/Variant_Combat/Interfaces",
			"UC_Spatial_Inventory/Variant_Combat/UI",
			"UC_Spatial_Inventory/Variant_SideScrolling",
			"UC_Spatial_Inventory/Variant_SideScrolling/AI",
			"UC_Spatial_Inventory/Variant_SideScrolling/Gameplay",
			"UC_Spatial_Inventory/Variant_SideScrolling/Interfaces",
			"UC_Spatial_Inventory/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
