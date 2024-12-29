// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "ConsoleCharacter.generated.h"

UCLASS()
class CONSOLERIFT_API AConsoleCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AConsoleCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input")
	class UInputMappingContext* ConsoleInputMappingContext;
	

	/*
	 * Input Actions
	 */
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	class UInputAction* IA_Move;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	UInputAction* IA_Look;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	UInputAction* IA_Jump;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	UInputAction* IA_Dodge;

	/*
	 * Function CalLbacks
	 */
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Jump();

	//Movement Varibales
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	float JumpHeight = 300;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	float DoubleJumpHeight = 500;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	bool MoveRelativeToCamera;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	float ForwardAxis;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	bool MoveOnlyInYAxis = false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Movement")
	bool Enable2DCamera;
	


	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class UCameraComponent* CameraView;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class USpringArmComponent* CameraBoom;


};
