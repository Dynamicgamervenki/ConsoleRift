// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Events/Trigger_Base.h"
#include "TriggerCardboard.generated.h"

/**
 * 
 */
UCLASS()
class CONSOLERIFT_API ATriggerCardboard : public ATrigger_Base
{
	GENERATED_BODY()

public:
	ATriggerCardboard();
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = Trigger)
	USkeletalMeshComponent* CardboardSkeletalMesh;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = Trigger)
	UBoxComponent* BoxCollider;
	

	virtual void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = Trigger)
	bool bCanFall = false;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Trigger)
	AActor* Camera;
	
	UFUNCTION(BlueprintCallable, Category = Trigger)
	void DisableBoxCollision();
	UFUNCTION(BlueprintCallable, Category = Trigger)
	void IgnorePlayerInput(bool Ignore);

	UPROPERTY()
	AActor* PlayerActor;
	
public:
	FORCEINLINE bool GetCanFall() const { return bCanFall; }
		
	
};
