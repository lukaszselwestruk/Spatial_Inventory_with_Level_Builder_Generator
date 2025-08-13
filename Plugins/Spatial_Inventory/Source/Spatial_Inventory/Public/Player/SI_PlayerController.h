// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SI_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class USI_HUDWidget;

UCLASS()
class SPATIAL_INVENTORY_API ASI_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ASI_PlayerController();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	void PrimaryInteract();
	void CreateHUDWidget();
	void TraceForItem();
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TArray<TObjectPtr<UInputMappingContext>> DefaultIMCs;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<UInputAction> PrimaryInteractAction;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TSubclassOf<USI_HUDWidget> HUDWidgetClass;

	UPROPERTY()
	TObjectPtr<USI_HUDWidget> HUDWidget;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	double TraceLength;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TEnumAsByte<ECollisionChannel> ItemTraceChannel;

	TWeakObjectPtr<AActor> ThisActor;
	TWeakObjectPtr<AActor> LastActor;
};
