// Copyright Epic Games, Inc. All Rights Reserved.

#include "Chip8Emulator.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FChip8EmulatorModule"

void FChip8EmulatorModule::StartupModule()
{
	FString BaseDir = IPluginManager::Get().FindPlugin("Chip8Emulator")->GetBaseDir();
	FString LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/Chip8EmulatorLibrary/Chip8.dll"));

	FLibraryHandle = FPlatformProcess::GetDllHandle(*LibraryPath);

	if(!FLibraryHandle)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not load Chip8.dll"));
	}
}

void FChip8EmulatorModule::ShutdownModule()
{
	FPlatformProcess::FreeDllHandle(FLibraryHandle);
	FLibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FChip8EmulatorModule, Chip8Emulator)