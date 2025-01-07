// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CardboardAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class CONSOLERIFT_API UCardboardAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	//functions
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	UPROPERTY(BlueprintReadOnly)
	class ATriggerCardboard* Cardboard;
	
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool bCanFall;
	
	
};
