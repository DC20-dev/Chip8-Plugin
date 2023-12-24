// Fill out your copyright notice in the Description page of Project Settings.


#include "CH8Factory.h"
#include "Chip8Rom.h"

UCH8Factory::UCH8Factory()
{
	bEditorImport = true;
	SupportedClass = UChip8Rom::StaticClass();
	Formats.Add(FString("ch8;ch8 Rom format"));
}

UObject* UCH8Factory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
	const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	UChip8Rom* Rom = NewObject<UChip8Rom>(InParent, InName, Flags);
	FFileHelper::LoadFileToArray(Rom->RomData, *Filename);
	Rom->SourceRomFile = InName.ToString();
	
	return Rom;
}
