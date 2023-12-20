// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomGenerator.h"

uint8_t RandomGenerator::GetRandomByte()
{
	return FMath::RandRange(0, 255);
}
