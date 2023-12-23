// Fill out your copyright notice in the Description page of Project Settings.


#include "Chip8.h"
#include "EmulatorInputConfig.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

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
	AutoPossessAI = EAutoPossessAI::Disabled;

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

void AChip8::KeyDownEventReceived(const chipotto::EmuKey key, const chipotto::InputType type)
{
	if (InputCommandInstance)
	{
		InputCommandInstance->EnqueueInputEvent(key, type);
		InputCommandInstance->UpdateKeyStatus(key, true);
	}
}

void AChip8::KeyUpEventReceived(const chipotto::EmuKey key)
{
	if (InputCommandInstance)
	{
		InputCommandInstance->UpdateKeyStatus(key, false);
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

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	// bind start actions
	Input->BindAction(InputConfiguration->Hex0, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_0, true);
	Input->BindAction(InputConfiguration->Hex1, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_1, true);
	Input->BindAction(InputConfiguration->Hex2, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_2, true);
	Input->BindAction(InputConfiguration->Hex3, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_3, true);
	Input->BindAction(InputConfiguration->Hex4, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_4, true);
	Input->BindAction(InputConfiguration->Hex5, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_5, true);
	Input->BindAction(InputConfiguration->Hex6, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_6, true);
	Input->BindAction(InputConfiguration->Hex7, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_7, true);
	Input->BindAction(InputConfiguration->Hex8, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_8, true);
	Input->BindAction(InputConfiguration->Hex9, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_9, true);
	Input->BindAction(InputConfiguration->HexA, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_A, true);
	Input->BindAction(InputConfiguration->HexB, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_B, true);
	Input->BindAction(InputConfiguration->HexC, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_C, true);
	Input->BindAction(InputConfiguration->HexD, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_D, true);
	Input->BindAction(InputConfiguration->HexE, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_E, true);
	Input->BindAction(InputConfiguration->HexF, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_F, true);
	Input->BindAction(InputConfiguration->HexQUIT, ETriggerEvent::Started, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_QUIT, true);

	// bind end actions
	Input->BindAction(InputConfiguration->Hex0, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_0, false);
	Input->BindAction(InputConfiguration->Hex1, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_1, false);
	Input->BindAction(InputConfiguration->Hex2, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_2, false);
	Input->BindAction(InputConfiguration->Hex3, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_3, false);
	Input->BindAction(InputConfiguration->Hex4, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_4, false);
	Input->BindAction(InputConfiguration->Hex5, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_5, false);
	Input->BindAction(InputConfiguration->Hex6, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_6, false);
	Input->BindAction(InputConfiguration->Hex7, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_7, false);
	Input->BindAction(InputConfiguration->Hex8, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_8, false);
	Input->BindAction(InputConfiguration->Hex9, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_9, false);
	Input->BindAction(InputConfiguration->HexA, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_A, false);
	Input->BindAction(InputConfiguration->HexB, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_B, false);
	Input->BindAction(InputConfiguration->HexC, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_C, false);
	Input->BindAction(InputConfiguration->HexD, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_D, false);
	Input->BindAction(InputConfiguration->HexE, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_E, false);
	Input->BindAction(InputConfiguration->HexF, ETriggerEvent::Completed, this, &AChip8::HexKeyboardKeyEvent, EEmulatorKeys::K_F, false);

	APlayerController* controller = Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(controller->GetLocalPlayer());
	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);
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

void AChip8::HexKeyboardKeyEvent(const EEmulatorKeys key, const bool isKeyDown)
{
	if (isKeyDown && key != EEmulatorKeys::K_QUIT)
	{
		KeyDownEventReceived(static_cast<chipotto::EmuKey>(key), chipotto::InputType::KEYDOWN);
	}
	else if (isKeyDown && key == EEmulatorKeys::K_QUIT)
	{
		KeyDownEventReceived(static_cast<chipotto::EmuKey>(key), chipotto::InputType::QUIT);
	}
	else
	{
		KeyUpEventReceived(static_cast<chipotto::EmuKey>(key));
	}
}
