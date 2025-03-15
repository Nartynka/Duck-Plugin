// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Ducks.generated.h"

UCLASS()
class DUCKPLUGIN_API ADucks : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Destroyed() override;
public:	
	// Sets default values for this actor's properties
	ADucks();

	UPROPERTY(EditAnywhere, Category = "Duck List")
	class UDuckList* DuckList;
	
	UFUNCTION(CallInEditor, Category = "Ducks")
	void CreateDucks();	
	UFUNCTION(CallInEditor, Category = "Ducks")
	void ClearDucks();
	UFUNCTION(CallInEditor, Category = "Ducks")
	void RefreshDucks();


	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
