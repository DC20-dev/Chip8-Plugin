// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class Chip8EmulatorLibrary : ModuleRules
{
	public Chip8EmulatorLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		PublicDefinitions.Add("CHIP8_IMPORT");
		
		PublicSystemIncludePaths.AddRange(
			new string[] {
				Path.Combine(ModuleDirectory, "Public"),
			}
			);

		PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "Chip8.lib"));

		PublicDelayLoadDLLs.Add("Chip8.dll");

		RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "Chip8.dll"));

	}
}
