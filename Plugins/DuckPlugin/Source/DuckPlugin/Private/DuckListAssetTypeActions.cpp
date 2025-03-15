// Fill out your copyright notice in the Description page of Project Settings.


#include "DuckListAssetTypeActions.h"
#include "DuckList.h"

UClass* FDuckListAssetTypeActions::GetSupportedClass() const
{
	return UDuckList::StaticClass();
}

FText FDuckListAssetTypeActions::GetName() const
{
	return FText::FromString("Duck List");
}

FColor FDuckListAssetTypeActions::GetTypeColor() const
{
	return FColor::Yellow;
}

uint32 FDuckListAssetTypeActions::GetCategories()
{
	return EAssetTypeCategories::Basic;
}
