// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DuckList.generated.h"

USTRUCT()
struct FDuckling 
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere)
	FString name;
	UPROPERTY(EditAnywhere)
	FColor color;
};


UCLASS(AutoExpandCategories = ("AllDucks"))
class DUCKPLUGIN_API UDuckList : public UObject
{
	GENERATED_BODY()

public:
//This will be stripped out in final game
# if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere)
	FString FilePath;
#endif

	UDuckList();

	UPROPERTY(EditAnywhere)
	FString Ducks;

	UPROPERTY(EditAnywhere)
	TArray<FDuckling> AllDucks;

	void Read();
	UFUNCTION(CallInEditor, meta = (ToolTip = "Read Json Ducks"), Category = "Better Buttons")
	void ReadJson();
	UFUNCTION(CallInEditor, meta = (ToolTip = "Write Json Ducks"), Category = "Better Buttons")
	void WriteJson();

	//UFUNCTION(CallInEditor, meta = (DisplayName = "Read Ducks", ToolTip = "Read Ducks"), Category = "Buttons")
	//UFUNCTION(CallInEditor, meta = (DisplayName = "Wrie Ducks", ToolTip = "Write Ducks"), Category = "Buttons")
	//void Write();
};