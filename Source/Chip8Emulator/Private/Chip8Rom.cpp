// Fill out your copyright notice in the Description page of Project Settings.


#include "Chip8Rom.h"

chipotto::Gamefile* UChip8Rom::GetNewGamefileFromRom() const
{
	chipotto::Gamefile* gamefile = new chipotto::Gamefile(RomData.Num());
	FMemory::Memcpy(gamefile->bytecode, RomData.GetData(), RomData.Num());
	return gamefile;
}
