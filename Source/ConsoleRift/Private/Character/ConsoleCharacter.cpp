// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ConsoleCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystemInterface.h"
#include  "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AConsoleCharacter::AConsoleCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	MoveRelativeToCamera = false;

	ConsoleInputMappingContext = CreateDefaultSubobject<UInputMappingContext>(TEXT("ConsoleInputMappingContext"));

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 360.f, 0.f);

	//Spring-Arm
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	CameraBoom->TargetArmLength = 300.0f; 
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->SetupAttachment(RootComponent);
	
	
	//Camera
	CameraView = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraView->SetupAttachment(CameraBoom);
	
}


void AConsoleCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))	
		{
			Subsystem->AddMappingContext(ConsoleInputMappingContext,0);
		}
	}
	
}

void AConsoleCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AConsoleCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	if (MoveRelativeToCamera)
	{
		FVector CameraForward = CameraView->GetForwardVector();
		FVector CameraRight = CameraView->GetRightVector();

		// Flatten the forward and right vectors to ensure movement stays horizontal
		CameraForward.Z = 0.0f;
		CameraRight.Z = 0.0f;

		// Normalize to avoid any scaling issues
		CameraForward.Normalize();
		CameraRight.Normalize();

		if (MoveOnlyInYAxis)
		{
			AddMovementInput(CameraForward, MovementVector.Y);
		}
		else
		{
			AddMovementInput(CameraForward, MovementVector.Y);
			AddMovementInput(CameraForward, MovementVector.X);
		}
		
	}
	else
	 {
		FRotator Rotation = Controller->GetControlRotation();
		
		FRotator YawRotation = FRotator(0.0f,Rotation.Yaw,0.0f);
		
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(ForwardDirection,MovementVector.Y);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(RightDirection,MovementVector.X);
	}


}

void AConsoleCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookDirection = Value.Get<FVector2D>();
	
	AddControllerYawInput(LookDirection.X);
	AddControllerPitchInput(LookDirection.Y);
}

void AConsoleCharacter::Jump()
{
	if (CanJump())
	{
		if (JumpCurrentCount == 0)
		{
			GetCharacterMovement()->JumpZVelocity = JumpHeight;
		}
		else if (JumpCurrentCount == 1)
		{
			GetCharacterMovement()->JumpZVelocity = DoubleJumpHeight;
		}
		Super::Jump();
	}
	
}


void AConsoleCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(IA_Move,ETriggerEvent::Triggered,this,&AConsoleCharacter::Move);
		EnhancedInputComponent->BindAction(IA_Look,ETriggerEvent::Triggered,this,&AConsoleCharacter::Look);
		EnhancedInputComponent->BindAction(IA_Jump,ETriggerEvent::Started,this,&AConsoleCharacter::Jump);
	}
}

