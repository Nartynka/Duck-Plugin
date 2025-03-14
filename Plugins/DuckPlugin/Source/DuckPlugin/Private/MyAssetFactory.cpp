// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAssetFactory.h"
#include "MyAsset.h"

UMyAssetFactory::UMyAssetFactory()
{
	//Formats.Add("JSON;JSON File (syn Jasona)");
	SupportedClass = UMyAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
	//bEditorImport = true;
	//UE_LOG(LogTemp, Warning, TEXT("Placki"));
}

UObject* UMyAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	check(InClass->IsChildOf(UMyAsset::StaticClass()));
	UMyAsset* CreatedAsset = NewObject<UMyAsset>(InParent, InClass, InName, Flags);
	return CreatedAsset;
}

//UObject* UJsonAssetFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
//{
//	UJsonAsset* CreatedFile = NewObject<UJsonAsset>(InParent, InClass, InName, Flags);
//	CreatedFile->FilePath = Filename;
//	UE_LOG(LogTemp, Warning, TEXT("AAAAAAAAAAA %s"), *Filename);
//	return CreatedFile;
//}

bool UMyAssetFactory::ShouldShowInNewMenu() const
{
	return true;
}
