#include "CPlayerAnimInstance.h"

#include "../Player/CPlayer.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


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
		FVector Velocity = OwnerCharacter->GetVelocity();
		Velocity.Z = 0;
		Speed = Velocity.Size();
	}


}
