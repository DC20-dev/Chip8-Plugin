// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Chip8Rom.h"
#include "CoreMinimal.h"
THIRD_PARTY_INCLUDES_START
#include "Chip8EmulatorLibrary/Public/emulator.h"
#include "Chip8EmulatorLibrary/Public/gamefile.h"
THIRD_PARTY_INCLUDES_END
#include "EmulatorKeys.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"
#include "InputCommands.h"
#include "RandomGenerator.h"
#include "Renderer.h"
#include "Chip8.generated.h"


UCLASS(Blueprintable, BlueprintType)
class CHIP8EMULATOR_API AChip8 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChip8();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ScreenMesh;

protected:

	UPROPERTY(BlueprintReadOnly)
	UTexture2D* Screen = nullptr;
	UPROPERTY(VisibleAnywhere)
	UMaterialInterface* ScreenMaterial = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FColor DefaultSpriteColor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FColor DefaultBackgroundColor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UChip8Rom* Rom = nullptr;
	UPROPERTY(BlueprintReadOnly)
	bool IsRunning = false;

	RandomGenerator* GeneratorInstance = nullptr;
	Renderer* RendererInstance = nullptr;
	InputCommands* InputCommandInstance = nullptr;
	chipotto::Emulator* EmulatorInstance = nullptr;
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial = nullptr;

	uint8 width = 64;
	uint8 height = 32;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;

	void KeyDownEventReceived(const chipotto::EmuKey, const chipotto::InputType);
	void KeyUpEventReceived(const chipotto::EmuKey key);

	UFUNCTION(CallInEditor)
	void Start();

	UFUNCTION(CallInEditor)
	void ClearScreen();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UMaterialInstanceDynamic* GetDynamicMaterialInstance() const;

	UFUNCTION(BlueprintCallable)
	void SetDoWrap(const bool DoWrap);

	UFUNCTION(BlueprintCallable)
	void SetSpritesTint(FColor tint);

	UFUNCTION(BlueprintCallable)
	void SetBackgroundTint(FColor tint);

	UFUNCTION(BlueprintCallable)
	FColor GetSpritesTint();

	UFUNCTION(BlueprintCallable)
	FColor GetBackgroundTint();

	UFUNCTION(BlueprintCallable)
	bool LoadRom(UChip8Rom* RomToLoad);

	UFUNCTION(BlueprintCallable)
	void SwitchON();

	UFUNCTION(BlueprintCallable)
	void SwitchOFF();

	UFUNCTION(BlueprintCallable)
	void Reboot();

	// UFUNCTION bound to the input system on possession.
	// This function is exposed to allow different input handling for the emulator
	// (ex. UMG buttons callbacks)

	UFUNCTION(BlueprintCallable)
	void HexKeyboardKeyEvent(const EEmulatorKeys key, const bool isKeyDown);
};
