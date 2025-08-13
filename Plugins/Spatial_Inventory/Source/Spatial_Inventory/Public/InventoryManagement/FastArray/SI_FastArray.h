#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "SI_FastArray.generated.h"

class USI_ItemComponent;
class USI_InventoryComponent;
class USI_InventoryItem;

/** A single entry in an inventory */
USTRUCT(BlueprintType)
struct FSI_InventoryEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

	FSI_InventoryEntry() {}

private:
	friend struct FInv_InventoryFastArray;
	friend USI_InventoryComponent;

	UPROPERTY()
	TObjectPtr<USI_InventoryItem> Item = nullptr;
};

/** List of inventory items */
USTRUCT(BlueprintType)
struct FSI_InventoryFastArray : public FFastArraySerializer
{
	GENERATED_BODY()

	FSI_InventoryFastArray() : OwnerComponent(nullptr) {}
	FSI_InventoryFastArray(UActorComponent* InOwnerComponent) : OwnerComponent(InOwnerComponent) {}

	TArray<USI_InventoryItem*> GetAllItems() const;

	// FFastArraySerializer contract
	void PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize);
	void PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize);
	// End of FFastArraySerializer contract

	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParams)
	{
		return FastArrayDeltaSerialize<FSI_InventoryEntry, FSI_InventoryFastArray>(Entries, DeltaParams, *this);
	}

	USI_InventoryItem* AddEntry(USI_ItemComponent* ItemComponent);
	USI_InventoryItem* AddEntry(USI_InventoryItem* Item);
	void RemoveEntry(USI_InventoryItem* Item);

private:
	friend USI_InventoryComponent;

	// Replicated list of items
	UPROPERTY()
	TArray<FSI_InventoryEntry> Entries;

	UPROPERTY(NotReplicated)
	TObjectPtr<UActorComponent> OwnerComponent;
};

template<>
struct TStructOpsTypeTraits<FSI_InventoryFastArray> : public TStructOpsTypeTraitsBase2<FInv_InventoryFastArray>
{
	enum { WithNetDeltaSerializer = true };
};