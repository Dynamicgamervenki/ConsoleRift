// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Events/Trigger_Base.h"
#include "TriggerCamera.generated.h"

/**
 * 
 */
UCLASS()
class CONSOLERIFT_API ATriggerCamera : public ATrigger_Base
{
	GENERATED_BODY()

	public:
	ATriggerCamera();

protected:
	virtual void BeginPlay() override;

	virtual void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera")
	float YawAngle = -90.0f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Camera")
	float TargetArmLength = 50.0f;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Camera")
	UAnimMontage* AM_Walk;
};
