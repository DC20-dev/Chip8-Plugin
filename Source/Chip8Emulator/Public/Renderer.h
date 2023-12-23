// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
THIRD_PARTY_INCLUDES_START
#include "Chip8EmulatorLibrary/Public/renderer.h"
THIRD_PARTY_INCLUDES_END

/**
 * 
 */
class CHIP8EMULATOR_API Renderer: public chipotto::EmuRenderer
{
public:
	Renderer(const int in_width, const int in_height, UTexture2D* virtualScreen);
	~Renderer();

	virtual void ClearScreen() override;
	virtual int Draw(uint8_t const x_coord, const uint8_t y_coord,
		const uint8_t* raw_sprite_mono, const uint8_t sprite_height, bool do_wrap,
		bool& out_collision) override;

	virtual bool IsValid() override;
	void SetSpritesTint(const FColor tint);
	void SetBackgroundTint(const FColor tint);
	FColor GetSpritesTint()const;
	FColor GetBackgroundTint() const;

protected:
	FColor ScreenTint = FColor::White;
	FColor BackgroundTint = FColor::Black;
	UTexture2D* EmulatorScreen = nullptr;
	FByteBulkData* ImageData = nullptr;
};
