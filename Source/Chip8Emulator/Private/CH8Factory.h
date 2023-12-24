// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "CH8Factory.generated.h"

/**
 * 
 */
UCLASS()
class UCH8Factory : public UFactory
{
	GENERATED_BODY()
public:

	UCH8Factory();

protected:
	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled);

	
};
