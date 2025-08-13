#include "InventoryManagement/FastArray/SI_FastArray.h"

#include "InventoryManagement/Components/SI_InventoryComponent.h"
#include "Items/SI_InventoryItem.h"

TArray<USI_InventoryItem*> FSI_InventoryFastArray::GetAllItems() const
{
	TArray<USI_InventoryItem*> Results;
	Results.Reserve(Entries.Num());
	for (const auto& Entry : Entries)
	{
		if (!IsValid(Entry.Item)) continue;
		Results.Add(Entry.Item);
	}
	return Results;
}

void FSI_InventoryFastArray::PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize)
{
	USI_InventoryComponent* IC = Cast<USI_InventoryComponent>(OwnerComponent);
	if (!IsValid(IC)) return;

	for (int32 Index : RemovedIndices)
	{
		IC->OnItemRemoved.Broadcast(Entries[Index].Item);
	}
}

void FSI_InventoryFastArray::PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize)
{
	USI_InventoryComponent* IC = Cast<USI_InventoryComponent>(OwnerComponent);
	if (!IsValid(IC)) return;
    	
	for (int32 Index : AddedIndices)
	{
		IC->OnItemAdded.Broadcast(Entries[Index].Item);
	}
}

USI_InventoryItem* FSI_InventoryFastArray::AddEntry(USI_ItemComponent* ItemComponent)
{
	// TODO: Implement once ItemComponent is more complete.
	return nullptr;
}

USI_InventoryItem* FSI_InventoryFastArray::AddEntry(USI_InventoryItem* Item)
{
	check(OwnerComponent);
	AActor* OwningActor = OwnerComponent->GetOwner();
	check(OwningActor->HasAuthority());

	FSI_InventoryEntry& NewEntry = Entries.AddDefaulted_GetRef();
	NewEntry.Item = Item;

	MarkItemDirty(NewEntry);
	return Item;
}

void FSI_InventoryFastArray::RemoveEntry(USI_InventoryItem* Item)
{
	for (auto EntryIt = Entries.CreateIterator(); EntryIt; ++EntryIt)
	{
		FSI_InventoryEntry& Entry = *EntryIt;
		if (Entry.Item == Item)
		{
			EntryIt.RemoveCurrent();
			MarkArrayDirty();
		}
	}
}