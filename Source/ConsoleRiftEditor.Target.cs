// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ConsoleRiftEditorTarget : TargetRules
{
	public ConsoleRiftEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		// Allow overriding build environment
		bOverrideBuildEnvironment = true;

		// Suppress backward-compatible build warnings
		DefaultBuildSettings = BuildSettingsVersion.V5;

		// Ensure the latest include order is used
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

		ExtraModuleNames.AddRange(new string[] { "ConsoleRift" });
	}
}