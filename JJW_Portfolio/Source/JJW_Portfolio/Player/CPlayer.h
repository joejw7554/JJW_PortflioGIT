#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"


struct FInputActionValue;
UCLASS()
class JJW_PORTFOLIO_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Sprint(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent* SpringArmComp;
protected:
	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputMappingContext* PlayerMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* LookAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* SprintAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	class UInputAction* JumpAction;

private:
	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float SprintSpeed = 600.f;

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float WalkSpeed = 400.f;


};
