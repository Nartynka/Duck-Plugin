// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAssetAssetTypeActions.h"
#include "MyAsset.h"

UClass* FMyAssetAssetTypeActions::GetSupportedClass() const
{
	return UMyAsset::StaticClass();
}

FText FMyAssetAssetTypeActions::GetName() const
{
	return FText::FromString("My Asset *Quack*");
}

FColor FMyAssetAssetTypeActions::GetTypeColor() const
{
	return FColor::Yellow;
}

uint32 FMyAssetAssetTypeActions::GetCategories()
{
	return EAssetTypeCategories::Basic;
}
