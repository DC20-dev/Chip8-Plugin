// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EmulatorInputConfig.generated.h"

class UInputAction;

/**
 * 
 */
UCLASS()
class CHIP8EMULATOR_API UEmulatorInputConfig : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* Hex0;
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* Hex1;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* Hex2;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* Hex3;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* Hex4;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* Hex5;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* Hex6;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* Hex7;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* Hex8;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* Hex9;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* HexA;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* HexB;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* HexC;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* HexD;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* HexE;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* HexF;		
	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly, Category = "Enhanced Input")
	UInputAction* HexQUIT;
};
