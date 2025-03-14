// Fill out your copyright notice in the Description page of Project Settings.


#include "Duck.h"
#include "SimpleDuckMesh.h"

// Sets default values
ADuck::ADuck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USimpleDuckMesh>("Mesh");
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ADuck::BeginPlay()
{
	Super::BeginPlay();
	Quack();
}

// Called every frame 
void ADuck::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADuck::Quack()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Quack!"));
}

void ADuck::SetMeshColor(FColor new_color)
{
	FLinearColor lin_color = new_color.ReinterpretAsLinear();
	FVector color = { lin_color.R, lin_color.G, lin_color.B };
	Mesh->SetDefaultCustomPrimitiveDataVector3(0, color);
}

