// Fill out your copyright notice in the Description page of Project Settings.


#include "Events/BlanceOnScale/TriggerBalance.h"
#include "Character/ConsoleCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void ATriggerBalance::BeginPlay()
{
	Super::BeginPlay();
}

void ATriggerBalance::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (AConsoleCharacter* ConsoleCharacter = Cast<AConsoleCharacter>(OtherActor))
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Yellow, "Hell Yeah");
		if (ConsoleCharacter->GetCharacterMovement()->IsFalling())
			return;
		
		ConsoleCharacter->bOnScale = true;
		ConsoleCharacter->PlayAnimMontage(AM_BalanceWalk,1);
		ConsoleCharacter->GetCharacterMovement()->MaxWalkSpeed = bBalanceWalkSpeed;

		OnTriggerBeginBlueprint(ConsoleCharacter);
	}
}

void ATriggerBalance::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AConsoleCharacter* ConsoleCharacter = Cast<AConsoleCharacter>(OtherActor);
	if (ConsoleCharacter)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Blue, "Hell Nah");

		ConsoleCharacter->bOnScale = false;
		if (AM_BalanceWalk)
		{
			ConsoleCharacter->StopAnimMontage(AM_BalanceWalk);
		}
		ConsoleCharacter->GetCharacterMovement()->MaxWalkSpeed = ConsoleCharacter->MovementSpeed;
		OnTriggerEndBlueprint(ConsoleCharacter);
	}
}

void ATriggerBalance::OnTriggerEndBlueprint_Implementation(AConsoleCharacter* ConsoleCharacter)
{
	GEngine->AddOnScreenDebugMessage(-101, 1, FColor::Cyan, "End From C++");
}

void ATriggerBalance::OnTriggerBeginBlueprint_Implementation(AConsoleCharacter* ConsoleCharacter)
{
	GEngine->AddOnScreenDebugMessage(-101, 1, FColor::Cyan, "Begin From C++");
}
