#include "RoomExitComponent.h"

URoomExitComponent::URoomExitComponent()
{
	SetCollisionProfileName(TEXT("GenerationData"));
	this->ComponentTags.Add("Door");
}


bool URoomExitComponent::HasSpawnedRoom()
{
	return (SpawnedRoom != nullptr);
}

