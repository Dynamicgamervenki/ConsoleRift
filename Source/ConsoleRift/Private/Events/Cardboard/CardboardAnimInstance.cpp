// Fill out your copyright notice in the Description page of Project Settings.


#include "Events/Cardboard/CardboardAnimInstance.h"

#include "Events/Cardboard/TriggerCardboard.h"

void UCardboardAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	AActor* OwnerActor  =GetOwningActor();
	
	if (OwnerActor)
	Cardboard = Cast<ATriggerCardboard>(OwnerActor);
	
}

void UCardboardAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (Cardboard)
	{
		bCanFall = Cardboard->GetCanFall();
	}
}
