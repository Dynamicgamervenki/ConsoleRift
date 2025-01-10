// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactions/Pull.h"

// Sets default values
APull::APull()
{
	PrimaryActorTick.bCanEverTick = true;

	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>("BlockMesh");
	SetRootComponent(BlockMesh);

	BlockMesh->SetCollisionObjectType(ECC_WorldDynamic);
	BlockMesh->SetCollisionResponseToAllChannels(ECR_Block);
	BlockMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	BlockMesh->SetGenerateOverlapEvents(true);
	
	
}

void APull::BeginPlay()
{
	Super::BeginPlay();
	
}

void APull::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APull::Interact()
{
	
}

