// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Duck.generated.h"

UCLASS()
class DUCKPLUGIN_API ADuck : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	class USimpleDuckMesh* Mesh;

public:	
	// Sets default values for this actor's properties
	ADuck();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Quack();

	void SetMeshColor(FColor new_color);
};
