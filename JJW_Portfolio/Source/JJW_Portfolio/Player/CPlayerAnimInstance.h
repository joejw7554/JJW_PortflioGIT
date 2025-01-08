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

	void CalculateSpeed();
	void CalculateDirection();
	void CheckGround();

protected:
	UPROPERTY(BlueprintReadOnly, Category=Movement)
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float Direction;

	UPROPERTY(EditDefaultsOnly, Category=Owner)
	class ACPlayer* OwnerCharacter;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool bFalling=false;

	
	
};
