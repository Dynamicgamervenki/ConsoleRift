// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Character/CharacterTypes.h"
#include "ConsoleAnimInstance.generated.h"


UCLASS()
class CONSOLERIFT_API UConsoleAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	public:

	//functions
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	UPROPERTY(BlueprintReadOnly)
	class AConsoleCharacter* ConsoleCharacter;
	
	UPROPERTY(BlueprintReadOnly,Category="Movement")
	class UCharacterMovementComponent* MovementComponent;
	
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float GroundSpeed;
	
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool IsFalling;
	
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	int JumpCount;

	ECharacterState CharacterState;
};
