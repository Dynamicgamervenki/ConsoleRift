// Fill out your copyright notice in the Description page of Project Settings.


#include "Events/Camera/TriggerCamera.h"

#include "Character/ConsoleCharacter.h"
#include "GameFramework/SpringArmComponent.h"

ATriggerCamera::ATriggerCamera()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxTrigger->ShapeColor = FColor::Orange;
	BoxTrigger->SetBoxExtent(FVector(63.0f, 11.47501f, 5.0f));
}

void ATriggerCamera::BeginPlay()
{
	Super::BeginPlay();
}

void ATriggerCamera::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AConsoleCharacter* ConsoleCharacter = Cast<AConsoleCharacter>(OtherActor))
	{
		ConsoleCharacter->SetCameraInput(false);
		ConsoleCharacter->CameraBoom->SetUsingAbsoluteRotation(true);
		ConsoleCharacter->CameraBoom->SetWorldRotation(FRotator(0, YawAngle, 0));
		ConsoleCharacter->SetEnable2DCamera(true);
		ConsoleCharacter->PlayAnimationMontage(AM_Walk);
		ConsoleCharacter->CameraBoom->TargetArmLength = TargetArmLength;
		// ConsoleCharacter->GetMesh()->PlayAnimation(WalkingAnimation,false);
		// ConsoleCharacter->IgnorePlayerInput(true,true);
		//
		// float AnimationDuration = WalkingAnimation->GetPlayLength();
		// FTimerHandle TimerHandle;
		// GetWorld()->GetTimerManager().SetTimer(TimerHandle, [ConsoleCharacter]()
		// {
		// 	// Enable player input after animation finishes
		// 	ConsoleCharacter->GetMesh()->SetAnimationMode(EAnimationMode::Type::AnimationBlueprint);
		// 	ConsoleCharacter->IgnorePlayerInput(false, false);
		// }, AnimationDuration, false);
	}
}

void ATriggerCamera::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (AConsoleCharacter* ConsoleCharacter = Cast<AConsoleCharacter>(OtherActor))
	{
		ConsoleCharacter->CameraBoom->SetUsingAbsoluteRotation(false);
		ConsoleCharacter->SetCameraInput(true);
		ConsoleCharacter->SetEnable2DCamera(false);
		ConsoleCharacter->CameraBoom->TargetArmLength = 70.0f;
	}
}

