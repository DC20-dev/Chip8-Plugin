// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
THIRD_PARTY_INCLUDES_START
#include "Chip8EmulatorLibrary/Public/iinput_command.h"
#include "Chip8EmulatorLibrary/Public/keys.h"
#include "Chip8EmulatorLibrary/Public/input_type.h"
THIRD_PARTY_INCLUDES_END

using KeyInputEvent = TTuple<chipotto::EmuKey, chipotto::InputType>;
/**
 * 
 */
class CHIP8EMULATOR_API InputCommands: public chipotto::IInputCommand
{
	// this class is required to pass input state information to the emulator, but to use it
	// we must have a way to get the input information from the Chip8 pawn class that uses
	// enhanced input system.
public:
	// for testing only in Chip8Emulator library, not needed here
	virtual const uint8_t* GetKeyboardState() override;
	virtual bool IsInputPending() override;
	virtual chipotto::EmuKey GetKey() override;
	virtual bool IsKeyPressed(const chipotto::EmuKey key) override;
	virtual chipotto::InputType GetInputEventType() override;

	// UE specific methods
	// call them when your desired input fires to inform the input command class
	
	// use this method to push a keydown or a quit event.
	void EnqueueInputEvent(const chipotto::EmuKey key, const chipotto::InputType type);
	// bind this to a change of pressed status and pass in the new status.
	void UpdateKeyStatus(const chipotto::EmuKey key, const bool IsPressed);

	InputCommands();
	~InputCommands();

protected:
	TQueue<KeyInputEvent> InputEventQueue;
	TStaticArray<bool, 0x10> KeyStatuses;
	KeyInputEvent PoppedInputEvent;
};
