

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "RoomExitComponent.generated.h"

class URoomWithSpawnRules;
class ULevelData;
class ABaseRoom;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEVELGENERATION_API URoomExitComponent : public UBoxComponent
{
	GENERATED_BODY()

public:	
	URoomExitComponent();
	UPROPERTY(VisibleAnywhere)
	TWeakObjectPtr<ABaseRoom> SpawnedRoom = nullptr;

	UFUNCTION(BlueprintCallable)
	bool HasSpawnedRoom();

private:
	UPROPERTY(EditAnywhere,meta=(AllowPrivateAccess= true))
	TArray<TObjectPtr<URoomWithSpawnRules>> RoomsWithRules = {};
};
