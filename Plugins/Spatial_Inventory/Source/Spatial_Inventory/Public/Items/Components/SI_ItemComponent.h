// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SI_ItemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class SPATIAL_INVENTORY_API USI_ItemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USI_ItemComponent();
	
	FString GetPickupMessage() const { return PickupMessage; }

private:
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FString PickupMessage;
};























