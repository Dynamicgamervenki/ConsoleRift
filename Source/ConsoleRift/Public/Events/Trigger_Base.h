// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Trigger_Base.generated.h"

UCLASS()
class CONSOLERIFT_API ATrigger_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	ATrigger_Base();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,Category="Trigger")
	USceneComponent* Root;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Trigger")
	UBoxComponent* BoxTrigger; 

	UFUNCTION()
	virtual void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent ,AActor* OtherActor ,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};