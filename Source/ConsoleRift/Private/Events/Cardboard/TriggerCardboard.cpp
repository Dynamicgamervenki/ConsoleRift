// Fill out your copyright notice in the Description page of Project Settings.


#include "Events/Cardboard/TriggerCardboard.h"

#include "Character/ConsoleCharacter.h"

ATriggerCardboard::ATriggerCardboard()
{
	PrimaryActorTick.bCanEverTick = false;
	CardboardSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName("SkeletalMesh"));
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollider"));

	CardboardSkeletalMesh->SetupAttachment(GetRootComponent());
	BoxCollider->SetupAttachment(CardboardSkeletalMesh);
	BoxTrigger->SetupAttachment(CardboardSkeletalMesh);

	CardboardSkeletalMesh->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);
	CardboardSkeletalMesh->SetCollisionProfileName(TEXT("Custom"));
	CardboardSkeletalMesh->SetCollisionObjectType(ECC_WorldStatic);
	CardboardSkeletalMesh->SetCollisionResponseToAllChannels(ECR_Block);
	CardboardSkeletalMesh->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	

	BoxTrigger->SetBoxExtent(FVector(5.0f, 5.0f, 20.0f));
	BoxTrigger->SetRelativeLocation(FVector(4.9, -0.3f, 27.4f));
	BoxTrigger->SetRelativeScale3D(FVector(0.7f,0.5f,0.1f));
	BoxTrigger->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);

	BoxCollider->SetRelativeLocation(FVector(4.6f,-0.000000f,26.563225f));
	BoxCollider->SetBoxExtent(FVector(3.0f,9.705735f,0.3f));
	

	BoxCollider->SetCollisionProfileName(TEXT("Custom"));	
	BoxCollider->SetGenerateOverlapEvents(true);
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::Type::QueryOnly);
	BoxCollider->SetCollisionObjectType(ECC_WorldDynamic);
	BoxCollider->SetCollisionResponseToAllChannels(ECR_Block);
	BoxCollider->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);
	BoxCollider->SetLineThickness(0.1f);
	BoxCollider->SetHiddenInGame(false);
	BoxCollider->ShapeColor = FColor::Green;
}

void ATriggerCardboard::BeginPlay()
{
	Super::BeginPlay();
}

void ATriggerCardboard::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnTriggerBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	GEngine->AddOnScreenDebugMessage(12,2.0f,FColor::Red,"TriggerCardboard Begin");
	bCanFall = true;
	PlayerActor = Cast<AConsoleCharacter>(OtherActor);
}

void ATriggerCardboard::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnTriggerEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	GEngine->AddOnScreenDebugMessage(12,2.0f,FColor::Green,"TriggerCardboard End");
	bCanFall = false;
}

void ATriggerCardboard::DisableBoxCollision()
{
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ATriggerCardboard::IgnorePlayerInput(bool Ignore)
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (Ignore)
		{
			PlayerController->SetIgnoreMoveInput(true);
			PlayerController->SetIgnoreLookInput(true);
			PlayerController->SetViewTargetWithBlend(Camera,0.5f);
		}
		else
		{
			PlayerController->SetIgnoreMoveInput(false);
			PlayerController->SetIgnoreLookInput(false);
			if (PlayerActor)
			{
				PlayerController->SetViewTargetWithBlend(PlayerActor,0.5f);
			}
		}
	}
}



