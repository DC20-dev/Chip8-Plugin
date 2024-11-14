// Fill out your copyright notice in the Description page of Project Settings.


#include "InputCommands.h"
#include "Chip8Emulator.h"

const uint8_t* InputCommands::GetKeyboardState()
{
	return nullptr;
}

bool InputCommands::IsInputPending()
{
	if (!InputEventQueue.IsEmpty())
	{
		InputEventQueue.Dequeue(PoppedInputEvent);
		return true;
	}
	return false;
}

chipotto::EmuKey InputCommands::GetKey()
{
	return PoppedInputEvent.Key;
}

bool InputCommands::IsKeyPressed(const chipotto::EmuKey key)
{
	return KeyStatuses[key];
}

chipotto::InputType InputCommands::GetInputEventType()
{
	return PoppedInputEvent.Value;
}

void InputCommands::EnqueueInputEvent(const chipotto::EmuKey key, const chipotto::InputType type)
{
	
	InputEventQueue.Enqueue(KeyInputEvent{key, type});
}

void InputCommands::UpdateKeyStatus(const chipotto::EmuKey key, const bool IsPressed)
{
	KeyStatuses[key] = IsPressed;
}

InputCommands::InputCommands()
{
}

InputCommands::~InputCommands()
{
	UE_LOG(LogChip8, Log, TEXT("InputCommands instance destroyed"));
}
