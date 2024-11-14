// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Chip8Pawn.generated.h"

class AChip8;
class UEmulatorInputConfig;
class UInputMappingContext;

UCLASS()
class CHIP8EMULATOR_API AChip8Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AChip8Pawn();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UEmulatorInputConfig* InputConfiguration = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UInputMappingContext* InputMapping = nullptr;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	AChip8* EmulatorActorInstance = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UChip8Rom* Rom = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	AChip8* GetEmulator() const;

};
