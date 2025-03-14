// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAsset.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"

#include "Serialization/JsonSerializer.h"

UMyAsset::UMyAsset()
{
	if (FilePath.IsEmpty())
		FilePath = FPaths::ProjectPluginsDir() + "DuckPlugin/Content/Example.json";
	UE_LOG(LogTemp, Warning, TEXT("Reading JSON..."));
	ReadJson();
}

void UMyAsset::Read()
{
	if (!FilePath.IsEmpty() && !FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to read from file - File doesn't exist - %s"), *FilePath);
	}

	FString OutString = "";

	if (!FFileHelper::LoadFileToString(OutString, *FilePath))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to read from file - Is this a text file? - %s"), *FilePath);
	}

	Ducks = OutString;
}

//void UMyAsset::Write()
//{
//	FFileHelper::SaveStringToFile(Ducks, *FilePath);
//}

void UMyAsset::ReadJson()
{
	AllDucks.Empty();
	Read();
	
	TSharedPtr<FJsonObject> JsonDucksObject;

	if (!FJsonSerializer::Deserialize(TJsonReaderFactory<>::Create(Ducks), JsonDucksObject))
	{
		UE_LOG(LogTemp, Error, TEXT("Read Json Failed, Failed to deserialize json string"));
		return;
	}

	TArray<TSharedPtr<FJsonValue>> DucksArray = JsonDucksObject->GetArrayField(TEXT("Ducks"));

	for (int i = 0; i < DucksArray.Num(); i++)
	{
		TSharedPtr<FJsonValue> value = DucksArray[i];
		TSharedPtr<FJsonObject> json = value->AsObject();

		FString DuckName = json->GetStringField(TEXT("name"));
		FString DuckColor = json->GetStringField(TEXT("color"));
		FDuckling duck = { DuckName, FColor::FromHex(DuckColor) };
		AllDucks.Push(duck);
	}
}

void UMyAsset::WriteJson()
{
	TArray<TSharedPtr<FJsonValue>> ObjArray;
	for (int i = 0; i < AllDucks.Num(); i++)
	{
		FDuckling curr_duck = AllDucks[i];
		TSharedPtr<FJsonObject> JsonObj = MakeShareable(new FJsonObject);
		JsonObj->SetStringField("name", curr_duck.name);
		JsonObj->SetStringField("color", curr_duck.color.ToHex());
		TSharedRef<FJsonValueObject> JsonValue = MakeShareable(new FJsonValueObject(JsonObj));
		ObjArray.Add(JsonValue);
	}

	TSharedPtr<FJsonObject> FinallObj = MakeShareable(new FJsonObject);
	FinallObj->SetArrayField("Ducks", ObjArray);
	FString JsonString;
	if (!FJsonSerializer::Serialize(FinallObj.ToSharedRef(), TJsonWriterFactory<>::Create(&JsonString, 0)))
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Writing Json to file: %s"), *JsonString);
	FFileHelper::SaveStringToFile(JsonString, *FilePath);
	ReadJson();
}
