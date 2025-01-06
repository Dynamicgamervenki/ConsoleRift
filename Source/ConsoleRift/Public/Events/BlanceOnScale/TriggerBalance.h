// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Events/Trigger_Base.h"
#include "TriggerBalance.generated.h"

class AConsoleCharacter;
/**
 * 
 */
UCLASS()
class CONSOLERIFT_API ATriggerBalance : public ATrigger_Base
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = TriggerBalance)
	UAnimMontage* AM_BalanceWalk;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = TriggerBalance)
	float bBalanceWalkSpeed = 4.0f;

protected:
	virtual void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	UFUNCTION(BlueprintNativeEvent)
	void OnTriggerBeginBlueprint(AConsoleCharacter* ConsoleCharacter);
	UFUNCTION(BlueprintNativeEvent)
	void OnTriggerEndBlueprint(AConsoleCharacter* ConsoleCharacter);
};
