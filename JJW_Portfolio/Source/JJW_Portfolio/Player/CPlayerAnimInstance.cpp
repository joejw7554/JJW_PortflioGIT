#include "CPlayerAnimInstance.h"

#include "../Player/CPlayer.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"


void UCPlayerAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	
	OwnerCharacter = Cast<ACPlayer>(TryGetPawnOwner());

	
}

void UCPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!!OwnerCharacter)
	{
		CalculateSpeed();
		CalculateDirection();
		CheckGround();
	}


}

void UCPlayerAnimInstance::CalculateSpeed()
{
	FVector Velocity = OwnerCharacter->GetVelocity();
	Velocity.Z = 0;
	Speed = Velocity.Size();
}

void UCPlayerAnimInstance::CalculateDirection()
{
	FVector CurrentDirection = OwnerCharacter->GetVelocity();
	FRotator Rotation = OwnerCharacter->GetActorRotation();
	Direction= UKismetAnimationLibrary::CalculateDirection(CurrentDirection, Rotation);
	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, FString::Printf(TEXT("%f"), Direction));
}

void UCPlayerAnimInstance::CheckGround()
{
	if (!!OwnerCharacter)
	{
		bFalling = OwnerCharacter	->GetCharacterMovement()->IsFalling();
	}
}
