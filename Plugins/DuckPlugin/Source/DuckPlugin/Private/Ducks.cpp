// Fill out your copyright notice in the Description page of Project Settings.


#include "Ducks.h"
#include "Duck.h"
#include "DuckList.h"

// Sets default values
ADucks::ADucks()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//ADucks::~ADucks()
//{
//	UE_LOG(LogTemp, Warning, TEXT("Trying to destroy ducks..."));
//	if (!DuckActors.IsEmpty())
//	{
//		UE_LOG(LogTemp, Warning, TEXT("Destroying ducks..."));
//		//for (ADuck* duck : DuckActors)
//		//	duck->Destroy();
//		DuckActors.Empty();
//	}
//}

void ADucks::OnConstruction(const FTransform& Transform)
{
	//if (!DuckList)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("DUCK LIST IS NOT SET"));
	//	return;
	//}

	//TArray<AActor*> AttachedActors;
	//GetAttachedActors(AttachedActors);
	//if (!DuckActors.IsEmpty())
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Ducks exists, returning.. num: %u, attached: %u"), DuckActors.Num(), AttachedActors.Num());
	//	return;
	//}

	//UE_LOG(LogTemp, Warning, TEXT("Attached ducks num: %u, num: %u"), AttachedActors.Num(), DuckActors.Num());
	//TArray<FDuckling> Ducks = DuckList->AllDucks;
	//UE_LOG(LogTemp, Warning, TEXT("Creating Ducks"));
	//for (FDuckling duck : Ducks)
	//{
	//	FVector duck_transform = GetActorLocation();
	//	duck_transform.X += 200 * DuckActors.Num();
	//	ADuck* new_duck = GetWorld()->SpawnActor<ADuck>(duck_transform, GetActorRotation());
	//	new_duck->SetActorLabel(duck.name);
	//	new_duck->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
	//	DuckActors.Push(new_duck);
	//}
}

void ADucks::Destroyed()
{
	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors);
	
	for (AActor* attached : AttachedActors)
		attached->Destroy();
}

// Called when the game starts or when spawned
void ADucks::BeginPlay()
{
	Super::BeginPlay();

}

void ADucks::CreateDucks()
{
	if (!DuckList)
	{
		UE_LOG(LogTemp, Error, TEXT("DUCK LIST IS NOT SET"));
		return;
	}

	DuckList->ReadJson();
	ClearDucks();

	TArray<FDuckling> Ducks = DuckList->AllDucks;
	UE_LOG(LogTemp, Warning, TEXT("Creating Ducks"));
	//int i = 0;
	//for (FDuckling duck : Ducks)
	for (int i = 0; i < Ducks.Num(); i++)
	{
		FDuckling duck = Ducks[i];
		FVector duck_transform = GetActorLocation();
		duck_transform.X += 200 * i;
		ADuck* new_duck = GetWorld()->SpawnActor<ADuck>(duck_transform, GetActorRotation());
		new_duck->SetActorLabel(duck.name);
		new_duck->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
		//i++;
		new_duck->SetMeshColor(duck.color);
	}
}

void ADucks::ClearDucks()
{
	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors);
	UE_LOG(LogTemp, Warning, TEXT("Clearing Ducks"));
	for (AActor* attached : AttachedActors)
		attached->Destroy();
}

void ADucks::RefreshDucks()
{
	TArray<AActor*> AttachedActors;
	GetAttachedActors(AttachedActors);
	if (AttachedActors.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("No ducks to update!"));
		return;
	}

	if (!DuckList)
	{
		UE_LOG(LogTemp, Error, TEXT("DUCK LIST IS NOT SET"));
		return;
	}

	DuckList->ReadJson();
	TArray<FDuckling> Ducks = DuckList->AllDucks;
	int j = Ducks.Num()-1;
	for (int i = 0; i < AttachedActors.Num(); i++)
	{
		if (ADuck* duck = Cast<ADuck>(AttachedActors[i]))
		{	
			duck->SetActorLabel(Ducks[j].name);
			duck->SetMeshColor(Ducks[j].color);
			j--;
		}
	}
}

// Called every frame
void ADucks::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

