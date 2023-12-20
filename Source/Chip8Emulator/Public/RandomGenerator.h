// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
THIRD_PARTY_INCLUDES_START
#include "Chip8EmulatorLibrary/Public/irandom_generator.h"
THIRD_PARTY_INCLUDES_END

class CHIP8EMULATOR_API RandomGenerator : public chipotto::IRandomGenerator
{
public:
	
	virtual uint8_t GetRandomByte() override;
};
