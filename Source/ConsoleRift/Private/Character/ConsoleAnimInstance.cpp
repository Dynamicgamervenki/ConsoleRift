// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ConsoleAnimInstance.h"

#include "Character/ConsoleCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interfaces/ITargetDevice.h"

void UConsoleAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	ConsoleCharacter = Cast<AConsoleCharacter>(TryGetPawnOwner());

	if (ConsoleCharacter)
	{
		MovementComponent = ConsoleCharacter->GetCharacterMovement();
	}

}

void UConsoleAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (ConsoleCharacter)
	{
		GroundSpeed = ConsoleCharacter->GetVelocity().Size2D();
		IsFalling = MovementComponent->IsFalling();
		JumpCount = ConsoleCharacter->JumpCurrentCount;
		CharacterState = ConsoleCharacter->GetCharacterState();
	}

}

