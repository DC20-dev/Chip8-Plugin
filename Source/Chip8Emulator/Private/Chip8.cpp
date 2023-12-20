// Fill out your copyright notice in the Description page of Project Settings.


#include "Chip8.h"

// Sets default values
AChip8::AChip8()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AChip8::BeginPlay()
{
	Super::BeginPlay();
	RendererInstance = new Renderer(64, 32, Screen);
	InputCommandInstance = new InputCommands();
	GeneratorInstance = new RandomGenerator();

	EmulatorInstance = new chipotto::Emulator(RendererInstance, InputCommandInstance, GeneratorInstance);
}

void AChip8::Destroyed()
{
	if (EmulatorInstance)
	{
		delete EmulatorInstance;
	}
}

// Called every frame
void AChip8::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	EmulatorInstance->Tick(DeltaTime);
}

// Called to bind functionality to input
void AChip8::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AChip8::HardReset()
{
	EmulatorInstance->HardResetEmulator();
}

void AChip8::SetDoWrap(const bool DoWrap)
{
	EmulatorInstance->SetDoWrap(DoWrap);
}

void AChip8::SetScreenTint(FColor tint)
{
	if (RendererInstance->IsValid())
	{
		RendererInstance->SetScreenTint(tint);
		// should trigger refresh
	}
}

void AChip8::SetBackgroundTint(FColor tint)
{
	if (RendererInstance->IsValid())
	{
		RendererInstance->SetBackgroundTint(tint);
		// should trigger refresh
	}
}

FColor AChip8::GetScreenTint()
{
	return RendererInstance->GetScreenTint();
}

FColor AChip8::GetBackgroundTint()
{
	return RendererInstance->GetBackgroundTint();
}