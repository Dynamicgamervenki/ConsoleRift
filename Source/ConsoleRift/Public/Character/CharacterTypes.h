#pragma once

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ECS_Uneqipped UMETA(DisplayName = "Uneqipped"),
	ECS_EqippedWeapon UMETA(DisplayName = "EqippedWeapon"),
	ECS_Balancing UMETA(DisplayName = "Balancing"),
	ECS_Pull UMETA(DisplayName = "Pull")
};
