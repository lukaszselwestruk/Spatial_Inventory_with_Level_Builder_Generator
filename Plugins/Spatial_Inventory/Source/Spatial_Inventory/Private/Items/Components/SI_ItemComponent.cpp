// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Components/SI_ItemComponent.h"


USI_ItemComponent::USI_ItemComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PickupMessage = FString("E - Pick Up");
}



