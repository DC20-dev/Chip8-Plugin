// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Chip8EmulatorLibrary/Public/keys.h"
#include "EmulatorKeys.generated.h"

UENUM(BlueprintType)
enum EEmulatorKeys
{
	K_0 = chipotto::EmuKey::K_0  UMETA(DisplayName = "0"),
	K_1 = chipotto::EmuKey::K_1 UMETA(DisplayName = "1"),
	K_2 = chipotto::EmuKey::K_2 UMETA(DisplayName = "2"),
	K_3 = chipotto::EmuKey::K_3 UMETA(DisplayName = "3"),
	K_4 = chipotto::EmuKey::K_4 UMETA(DisplayName = "4"),
	K_5 = chipotto::EmuKey::K_5 UMETA(DisplayName = "5"),
	K_6 = chipotto::EmuKey::K_6 UMETA(DisplayName = "6"),
	K_7 = chipotto::EmuKey::K_7 UMETA(DisplayName = "7"),
	K_8 = chipotto::EmuKey::K_8 UMETA(DisplayName = "8"),
	K_9 = chipotto::EmuKey::K_9 UMETA(DisplayName = "9"),
	K_A = chipotto::EmuKey::K_A UMETA(DisplayName = "A"),
	K_B = chipotto::EmuKey::K_B UMETA(DisplayName = "B"),
	K_C = chipotto::EmuKey::K_C UMETA(DisplayName = "C"),
	K_D = chipotto::EmuKey::K_D UMETA(DisplayName = "D"),
	K_E = chipotto::EmuKey::K_E UMETA(DisplayName = "E"),
	K_F = chipotto::EmuKey::K_F UMETA(DisplayName = "F"),
	K_QUIT = chipotto::EmuKey::K_NONE UMETA(DisplayName = "QUIT")
};
