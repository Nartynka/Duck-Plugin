// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleDuckMesh.h"

USimpleDuckMesh::USimpleDuckMesh()
{
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/DuckPlugin/Duck/SM_Duck.SM_Duck'"));
	this->SetStaticMesh(MeshAsset.Object);
}
