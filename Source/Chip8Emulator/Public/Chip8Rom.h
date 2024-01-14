// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Chip8EmulatorLibrary/Public/gamefile.h"
#include "Chip8Rom.generated.h"

class UCH8Factory;

/**
 * 
 */
UCLASS()
class CHIP8EMULATOR_API UChip8Rom : public UObject
{
	GENERATED_BODY()
protected:

#if WITH_EDITORONLY_DATA

	UPROPERTY(VisibleAnywhere)
	FString SourceRomFile;
#endif
#if WITH_EDITOR
	friend class UCH8Factory;
#endif
	UPROPERTY()
	TArray<uint8> RomData;
	
public:
	chipotto::Gamefile* GetNewGamefileFromRom() const;
};
