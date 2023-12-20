// Fill out your copyright notice in the Description page of Project Settings.


#include "InputCommands.h"

const uint8_t* InputCommands::GetKeyboardState()
{
	return nullptr;
}

bool InputCommands::IsInputPending()
{
	return false;
}

chipotto::EmuKey InputCommands::GetKey()
{
	return chipotto::EmuKey();
}

bool InputCommands::IsKeyPressed(const chipotto::EmuKey key)
{
	return false;
}

chipotto::InputType InputCommands::GetInputEventType()
{
	return chipotto::InputType();
}

InputCommands::InputCommands()
{
}

InputCommands::~InputCommands()
{
}
