// Fill out your copyright notice in the Description page of Project Settings.


#include "DuckListFactory.h"
#include "DuckList.h"

UDuckListFactory::UDuckListFactory()
{
	//Formats.Add("JSON;JSON File (syn Jasona)");
	SupportedClass = UDuckList::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
	//bEditorImport = true;
	//UE_LOG(LogTemp, Warning, TEXT("Placki"));
}

UObject* UDuckListFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	check(InClass->IsChildOf(UDuckList::StaticClass()));
	UDuckList* CreatedAsset = NewObject<UDuckList>(InParent, InClass, InName, Flags);
	return CreatedAsset;
}

//UObject* UJsonAssetFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
//{
//	UJsonAsset* CreatedFile = NewObject<UJsonAsset>(InParent, InClass, InName, Flags);
//	CreatedFile->FilePath = Filename;
//	UE_LOG(LogTemp, Warning, TEXT("AAAAAAAAAAA %s"), *Filename);
//	return CreatedFile;
//}

bool UDuckListFactory::ShouldShowInNewMenu() const
{
	return true;
}
