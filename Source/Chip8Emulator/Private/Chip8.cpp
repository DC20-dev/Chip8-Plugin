// Fill out your copyright notice in the Description page of Project Settings.


#include "Chip8.h"
#include "Chip8Emulator.h"

// Sets default values
AChip8::AChip8()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("Engine.Material'/Chip8Emulator/M_Chip8ScreenMaster.M_Chip8ScreenMaster'"));
	if (FoundMaterial.Object)
	{
		ScreenMaterial = FoundMaterial.Object;
	}

	DefaultBackgroundColor = FColor::Black;
	DefaultSpriteColor = FColor::White;

	ScreenMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Test Mesh"));
	RootComponent = ScreenMesh;
}

// Called when the game starts or when spawned
void AChip8::BeginPlay()
{
	Super::BeginPlay();

	RendererInstance = new Renderer(width, height, &Screen);
	InputCommandInstance = new InputCommands();
	GeneratorInstance = new RandomGenerator();

	EmulatorInstance = new chipotto::Emulator(RendererInstance, InputCommandInstance, GeneratorInstance);

	// get the predefined material in content

	DynamicMaterial = UMaterialInstanceDynamic::Create(ScreenMaterial, this);
	DynamicMaterial->SetTextureParameterValue("ScreenTexture", Screen);
	SetSpritesTint(DefaultSpriteColor);
	SetBackgroundTint(DefaultBackgroundColor);
	ScreenMesh->SetMaterial(0, DynamicMaterial);

	if (Rom)
	{
		EmulatorInstance->Load(Rom->GetNewGamefileFromRom());
		UE_LOG(LogChip8, Log, TEXT("Loaded Rom in begin play"));
	}
	RendererInstance->ClearScreen();
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
	UE_LOG(LogChip8, Log, TEXT("Key down event received; input command instance: %s"), InputCommandInstance ? TEXT("True") : TEXT("False"));
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
	if (IsRunning)
	{
		bool TickResult = EmulatorInstance->Tick(DeltaTime);
		if (!TickResult) 
		{
			UE_LOG(LogChip8, Log, TEXT("EmulatorInstance tick returns false"));
		}
	}
}

UMaterialInstanceDynamic* AChip8::GetDynamicMaterialInstance() const
{
	return DynamicMaterial;
}

void AChip8::SetDoWrap(const bool DoWrap)
{
	EmulatorInstance->SetDoWrap(DoWrap);
}

void AChip8::SetSpritesTint(FColor tint)
{
	if (RendererInstance->IsValid())
	{
		RendererInstance->SetSpritesTint(tint);
		DynamicMaterial->SetVectorParameterValue("SpritesTint", tint);
	}
}

void AChip8::SetBackgroundTint(FColor tint)
{
	if (RendererInstance->IsValid())
	{
		RendererInstance->SetBackgroundTint(tint);
		DynamicMaterial->SetVectorParameterValue("BackgroundTint", tint);
	}
}

FColor AChip8::GetSpritesTint()
{
	if (RendererInstance->IsValid())
	{
		return RendererInstance->GetSpritesTint();
	}
	return FColor::White;
}

FColor AChip8::GetBackgroundTint()
{
	if (RendererInstance->IsValid())
	{
		return RendererInstance->GetBackgroundTint();
	}
	return FColor::Black;
}

bool AChip8::LoadRom(UChip8Rom* RomToLoad)
{
	EmulatorInstance->HardResetEmulator();
	if (EmulatorInstance->Load(RomToLoad->GetNewGamefileFromRom()))
	{
		Rom = RomToLoad;
		return true;
	}
	return false;
}

void AChip8::SwitchON()
{
	IsRunning = true;
}

void AChip8::SwitchOFF()
{
	IsRunning = false;
	EmulatorInstance->HardResetEmulator();
}

void AChip8::Reboot()
{
	SwitchOFF();
	FTimerHandle timerHandle;
	GetWorldTimerManager().SetTimer(timerHandle, this, &AChip8::SwitchON, 1.5f);
}

void AChip8::Start()
{
	SwitchON();
}

void AChip8::ClearScreen()
{
	RendererInstance->ClearScreen();
}

void AChip8::HexKeyboardKeyEvent(const EEmulatorKeys key, const bool isKeyDown)
{
	if (isKeyDown && key != EEmulatorKeys::K_QUIT)
	{
		KeyDownEventReceived(static_cast<chipotto::EmuKey>(key), chipotto::InputType::KEYDOWN);
		UE_LOG(LogChip8, Log, TEXT("Key down event"));
	}
	else if (isKeyDown && key == EEmulatorKeys::K_QUIT)
	{
		KeyDownEventReceived(static_cast<chipotto::EmuKey>(key), chipotto::InputType::QUIT);
		UE_LOG(LogChip8, Log, TEXT("Quit event"));
	}
	else
	{
		KeyUpEventReceived(static_cast<chipotto::EmuKey>(key));
		UE_LOG(LogChip8, Log, TEXT("Key up event"));
	}
}
