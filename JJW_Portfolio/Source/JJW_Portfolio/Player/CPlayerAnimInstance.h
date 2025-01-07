#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CPlayerAnimInstance.generated.h"

UCLASS()
class JJW_PORTFOLIO_API UCPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	void NativeBeginPlay() override;

	void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category=Movement)
	float Speed;

	UPROPERTY(EditDefaultsOnly, Category=Owner)
	class ACPlayer* OwnerCharacter;

	
	
};
