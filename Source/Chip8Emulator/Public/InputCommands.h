// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
THIRD_PARTY_INCLUDES_START
#include "Chip8EmulatorLibrary/Public/iinput_command.h"
#include "Chip8EmulatorLibrary/Public/keys.h"
#include "Chip8EmulatorLibrary/Public/input_type.h"
THIRD_PARTY_INCLUDES_END

/**
 * 
 */
class CHIP8EMULATOR_API InputCommands: public chipotto::IInputCommand
{
public:

	virtual const uint8_t* GetKeyboardState() override;
	virtual bool IsInputPending() override;
	virtual chipotto::EmuKey GetKey() override;
	virtual bool IsKeyPressed(const chipotto::EmuKey key) override;
	virtual chipotto::InputType GetInputEventType() override;

	InputCommands();
	~InputCommands();
};
