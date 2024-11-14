// Fill out your copyright notice in the Description page of Project Settings.


#include "Chip8Pawn.h"
#include "Chip8.h"
#include "EmulatorInputConfig.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"


// Sets default values
AChip8Pawn::AChip8Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessAI = EAutoPossessAI::Disabled;

	ConstructorHelpers::FObjectFinder<UEmulatorInputConfig> FoundInputConfig(TEXT(
		"Chip8Emulator.EmulatorInputConfig'/Chip8Emulator/DA_DefaultEmulatorInputConfig.DA_DefaultEmulatorInputConfig'"));
	if (FoundInputConfig.Object)
	{
		InputConfiguration = FoundInputConfig.Object;
	}

	ConstructorHelpers::FObjectFinder<UInputMappingContext> FoundInputMappingContext(
		TEXT("EnhancedInput.InputMappingContext'/Chip8Emulator/IMC_DefaultEmulatorInputMappingContext.IMC_DefaultEmulatorInputMappingContext'"));
	if (FoundInputMappingContext.Object)
	{
		InputMapping = FoundInputMappingContext.Object;
	}
}

// Called when the game starts or when spawned
void AChip8Pawn::BeginPlay()
{
	Super::BeginPlay();
	EmulatorActorInstance = GetWorld()->SpawnActor<AChip8>(GetActorLocation(), GetActorRotation());
	if (Rom)
	{
		EmulatorActorInstance->LoadRom(Rom);
	}
	EmulatorActorInstance->SwitchON();
}

// Called every frame
void AChip8Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AChip8Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	// bind start actions
	Input->BindAction(InputConfiguration->Hex0, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_0, true);
	Input->BindAction(InputConfiguration->Hex1, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_1, true);
	Input->BindAction(InputConfiguration->Hex2, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_2, true);
	Input->BindAction(InputConfiguration->Hex3, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_3, true);
	Input->BindAction(InputConfiguration->Hex4, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_4, true);
	Input->BindAction(InputConfiguration->Hex5, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_5, true);
	Input->BindAction(InputConfiguration->Hex6, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_6, true);
	Input->BindAction(InputConfiguration->Hex7, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_7, true);
	Input->BindAction(InputConfiguration->Hex8, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_8, true);
	Input->BindAction(InputConfiguration->Hex9, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_9, true);
	Input->BindAction(InputConfiguration->HexA, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_A, true);
	Input->BindAction(InputConfiguration->HexB, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_B, true);
	Input->BindAction(InputConfiguration->HexC, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_C, true);
	Input->BindAction(InputConfiguration->HexD, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_D, true);
	Input->BindAction(InputConfiguration->HexE, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_E, true);
	Input->BindAction(InputConfiguration->HexF, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_F, true);
	Input->BindAction(InputConfiguration->HexQUIT, ETriggerEvent::Started, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_QUIT, true);

	// bind end actions
	Input->BindAction(InputConfiguration->Hex0, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_0, false);
	Input->BindAction(InputConfiguration->Hex1, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_1, false);
	Input->BindAction(InputConfiguration->Hex2, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_2, false);
	Input->BindAction(InputConfiguration->Hex3, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_3, false);
	Input->BindAction(InputConfiguration->Hex4, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_4, false);
	Input->BindAction(InputConfiguration->Hex5, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_5, false);
	Input->BindAction(InputConfiguration->Hex6, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_6, false);
	Input->BindAction(InputConfiguration->Hex7, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_7, false);
	Input->BindAction(InputConfiguration->Hex8, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_8, false);
	Input->BindAction(InputConfiguration->Hex9, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_9, false);
	Input->BindAction(InputConfiguration->HexA, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_A, false);
	Input->BindAction(InputConfiguration->HexB, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_B, false);
	Input->BindAction(InputConfiguration->HexC, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_C, false);
	Input->BindAction(InputConfiguration->HexD, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_D, false);
	Input->BindAction(InputConfiguration->HexE, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_E, false);
	Input->BindAction(InputConfiguration->HexF, ETriggerEvent::Completed, EmulatorActorInstance, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_F, false);

	APlayerController* controller = Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(controller->GetLocalPlayer());
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);
}

AChip8* AChip8Pawn::GetEmulator() const
{
	return EmulatorActorInstance;
}

