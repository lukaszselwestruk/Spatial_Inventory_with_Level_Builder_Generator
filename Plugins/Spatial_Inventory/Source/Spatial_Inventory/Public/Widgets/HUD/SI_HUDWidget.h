// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SI_HUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class SPATIAL_INVENTORY_API USI_HUDWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Intentory")
	void ShowPickupMessage(const FString& Message);

	UFUNCTION(BlueprintImplementableEvent, Category = "Intentory")
	void HidePickupMessage();
};
