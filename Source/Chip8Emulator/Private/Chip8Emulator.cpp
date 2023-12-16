// Copyright Epic Games, Inc. All Rights Reserved.

#include "Chip8Emulator.h"
#include "Interfaces/IPluginManager.h"
THIRD_PARTY_INCLUDES_START
#include "Chip8EmulatorLibrary/Public/emulator.h"
THIRD_PARTY_INCLUDES_END

#define LOCTEXT_NAMESPACE "FChip8EmulatorModule"

void FChip8EmulatorModule::StartupModule()
{
	FString BaseDir = IPluginManager::Get().FindPlugin("Chip8Emulator")->GetBaseDir();
	FString LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/Chip8EmulatorLibrary/Chip8.dll"));

	FLibraryHandle = FPlatformProcess::GetDllHandle(*LibraryPath);
	UE_LOG(LogTemp, Error, TEXT(""));

	if (FLibraryHandle)
	{
		chipotto::Emulator emu = chipotto::Emulator(nullptr, nullptr, nullptr);
		chipotto::Gamefile gamefile = chipotto::Gamefile(100);
		if (emu.Load(&gamefile))
		{
			UE_LOG(LogTemp, Error, TEXT("emulator didn't load the placeholder gamefile"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Gamefile loaded"));

		}
	}
	else
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