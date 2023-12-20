// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
THIRD_PARTY_INCLUDES_START
#include "Chip8EmulatorLibrary/Public/emulator.h"
#include "Chip8EmulatorLibrary/Public/gamefile.h"
THIRD_PARTY_INCLUDES_END
#include "GameFramework/Pawn.h"
#include "InputCommands.h"
#include "RandomGenerator.h"
#include "Renderer.h"
#include "Chip8.generated.h"

UCLASS()
class CHIP8EMULATOR_API AChip8 : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChip8();

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UTexture2D* Screen;

protected:

	RandomGenerator* GeneratorInstance = nullptr;
	Renderer* RendererInstance = nullptr;
	InputCommands* InputCommandInstance = nullptr;
	chipotto::Emulator* EmulatorInstance = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void HardReset();

	UFUNCTION(BlueprintCallable)
	void SetDoWrap(const bool DoWrap);

	UFUNCTION(BlueprintCallable)
	void SetScreenTint(FColor tint);

	UFUNCTION(BlueprintCallable)
	void SetBackgroundTint(FColor tint);

	UFUNCTION(BlueprintCallable)
	FColor GetScreenTint();

	UFUNCTION(BlueprintCallable)
	FColor GetBackgroundTint();
};
