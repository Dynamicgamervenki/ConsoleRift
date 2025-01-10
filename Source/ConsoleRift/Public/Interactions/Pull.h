// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/InteractInterface.h"
#include "Pull.generated.h"

UCLASS()
class CONSOLERIFT_API APull : public AActor , public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	APull();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Interact")
	UStaticMeshComponent* BlockMesh;
	

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void Interact() override;
};
