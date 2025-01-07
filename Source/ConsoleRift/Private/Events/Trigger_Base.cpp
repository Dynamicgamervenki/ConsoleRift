// Fill out your copyright notice in the Description page of Project Settings.


#include "Events/Trigger_Base.h"


ATrigger_Base::ATrigger_Base()
{
	PrimaryActorTick.bCanEverTick = true;
	BoxTrigger = CreateDefaultSubobject<UBoxComponent>(FName("Trigger Begin"));

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	SetRootComponent(Root);
	BoxTrigger->SetupAttachment(Root);
	BoxTrigger->SetBoxExtent(FVector(5.0f, 5.0f, 5.0f));
	BoxTrigger->SetHiddenInGame(false);
	BoxTrigger->SetLineThickness(0.1f);
	BoxTrigger->ShapeColor = FColor::Red;
}

void ATrigger_Base::BeginPlay()
{
	Super::BeginPlay();

	BoxTrigger->OnComponentBeginOverlap.AddDynamic(this,&ATrigger_Base::OnTriggerBeginOverlap);
	BoxTrigger->OnComponentEndOverlap.AddDynamic(this,&ATrigger_Base::OnTriggerEndOverlap);
}

void ATrigger_Base::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "Begin Trigger");
		}
}

void ATrigger_Base::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, "End Trigger");
	}
}


void ATrigger_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

