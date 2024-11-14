// Fill out your copyright notice in the Description page of Project Settings.


#include "Renderer.h"
#include "Chip8Emulator.h"

Renderer::Renderer(const int in_width, const int in_height, UTexture2D** virtualScreen):
	EmuRenderer(in_width, in_height)
{

	EmulatorScreen = UTexture2D::CreateTransient(width, height, EPixelFormat::PF_G8);
	EmulatorScreen->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	EmulatorScreen->CompressionSettings = TextureCompressionSettings::TC_Grayscale;
	EmulatorScreen->SRGB = false;
	EmulatorScreen->Filter = TextureFilter::TF_Nearest;
	EmulatorScreen->UpdateResource();
	// BGRA8
	*virtualScreen = EmulatorScreen;

	FTexture2DMipMap* Mipmap = &(EmulatorScreen->GetPlatformData()->Mips[0]);
	ImageData = &(Mipmap->BulkData);
}

Renderer::~Renderer()
{
}

void Renderer::ClearScreen()
{
	if (!IsValid())
	{
		UE_LOG(LogChip8, Error, TEXT("Renderer is not valid!"));
		return;
	}
	uint8* RawScreenData = (uint8*)ImageData->Lock(LOCK_READ_WRITE);
	
	for (size_t i = 0; i < width * height; i++)
	{
		//G
		RawScreenData[i] = 0x00;
	}

	ImageData->Unlock();
	EmulatorScreen->UpdateResource();
}

int Renderer::Draw(uint8_t const x_coord, const uint8_t y_coord,
	const uint8_t* raw_sprite_mono, const uint8_t sprite_height,
	bool do_wrap, bool& out_collision)
{
	if (!IsValid())
	{
		UE_LOG(LogChip8, Error, TEXT("Renderer is not valid!"));
		return -1;
	}

	uint8* RawScreenData = (uint8*)ImageData->Lock(LOCK_READ_WRITE);

	int pitch = width;

	for (int y = 0; y < sprite_height; ++y)
	{
		if (!do_wrap && y + y_coord >= height)
			break;
		uint8_t row_byte = raw_sprite_mono[y];
		for (int x = 0; x < 8; x++)
		{
			uint8_t pixel_color = (row_byte >> (7 - x)) & 0x1;
			uint8_t color = 0;
			if (pixel_color)
			{
				color = 0xFF;
			}
			if (!do_wrap && x + x_coord >= width)
				break;
			int pixel_index = ((x + x_coord) % width) + pitch * ((y + y_coord) % height);
			uint8_t existing_pixel = RawScreenData[pixel_index];
			color ^= existing_pixel;

			if (existing_pixel != 0 && color != 0)
			{
				out_collision = true;
			}

			RawScreenData[pixel_index] = color;
		}
	}

	ImageData->Unlock();
	EmulatorScreen->UpdateResource();

	return 0;
}

bool Renderer::IsValid()
{
	return EmulatorScreen->IsValidLowLevel() && ImageData != nullptr;
}

void Renderer::SetSpritesTint(const FColor tint)
{
	ScreenTint = tint;
}

void Renderer::SetBackgroundTint(const FColor tint)
{
	BackgroundTint = tint;
}

FColor Renderer::GetSpritesTint() const
{
	return ScreenTint;
}

FColor Renderer::GetBackgroundTint() const
{
	return BackgroundTint;
}
